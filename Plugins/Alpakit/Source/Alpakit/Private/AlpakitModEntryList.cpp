#include "AlpakitModEntryList.h"

#include "AlpakitModEntry.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "AlpakitModListEntry"

void SAlpakitModEntryList::Construct(const FArguments& Args) {
	ChildSlot[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot().AutoHeight()[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().AutoWidth()[
				SNew(SButton)
				.Text(LOCTEXT("PackageModAlpakitAll", "Alpakit All!"))
				.OnClicked(this,& SAlpakitModEntryList::PackageAllMods)
			]
		]
		+ SVerticalBox::Slot().AutoHeight()[
			SAssignNew(ModList, SListView<TSharedRef<IPlugin>>)
			.SelectionMode(ESelectionMode::None)
			.ListItemsSource(&FilteredMods)
			.OnGenerateRow_Lambda(
	           [this](TSharedRef<IPlugin> Mod, const TSharedRef<STableViewBase>& List) {
	               return SNew(STableRow<TSharedRef<IPlugin>>, List)[
	                   SNew(SAlpakitModEntry, Mod, SharedThis(this))
	               ];
	           })
		]];

	LoadMods();
}

bool DoesPluginHaveRuntime(const IPlugin& Plugin) {
	//Content plugins always have runtime component
	if (Plugin.GetDescriptor().bCanContainContent) {
		return true;
	}
	//C++ plugins have runtime component as long as one of their modules does
	for (const FModuleDescriptor& Module : Plugin.GetDescriptor().Modules) {
		if (Module.Type == EHostType::Runtime ||
			Module.Type == EHostType::RuntimeNoCommandlet ||
			Module.Type == EHostType::RuntimeAndProgram ||
			Module.Type == EHostType::ClientOnly ||
			Module.Type == EHostType::ClientOnlyNoCommandlet ||
			Module.Type == EHostType::ServerOnly ||
			Module.Type == EHostType::CookedOnly) {
			return true;
		}
	}
	return false;
}

void SAlpakitModEntryList::LoadMods() {
	Mods.Empty();
	const TArray<TSharedRef<IPlugin>> EnabledPlugins = IPluginManager::Get().GetEnabledPlugins();
	for (TSharedRef<IPlugin> Plugin : EnabledPlugins) {
		//Skip WWise, it is already shipped with the game
		if (Plugin->GetName() == TEXT("WWise")) {
			continue;
		}
		//Only include project plugins for now
		//TODO make sure UAT task supports engine plugins
		if ((bShowEngine && Plugin->GetType() == EPluginType::Engine) || Plugin->GetType() == EPluginType::Project) {
			const bool bHasRuntime = DoesPluginHaveRuntime(Plugin.Get());
			if (bHasRuntime) {
				Mods.Add(Plugin);
			}
		}
	}
	Mods.Sort([](const TSharedRef<IPlugin> Plugin1, const TSharedRef<IPlugin> Plugin2) {
		return Plugin1->GetName() < Plugin2->GetName();
	});
	Filter(LastFilter);
}

bool PluginMatchesSearchTokens(const IPlugin& Plugin, const TArray<FString>& Tokens) {
	const FString PluginName = Plugin.GetName();
	const FString FriendlyName = Plugin.GetDescriptor().FriendlyName;
	const FString Description = Plugin.GetDescriptor().Description;

	for (const FString& Token : Tokens) {
		if (PluginName.Contains(Token) ||
			FriendlyName.Contains(Token) ||
			Description.Contains(Token)) {
			return true;
		}
	}
	return false;
}

void SAlpakitModEntryList::Filter(const FString& InFilter) {
	LastFilter = InFilter;
	FilteredMods.Empty();

	if (InFilter.IsEmpty()) 	{
		FilteredMods = Mods;
	} else {
		// tokenize filter keywords
		TArray<FString> FilterTokens;
		InFilter.ParseIntoArray(FilterTokens, TEXT(" "), true);

		// check each mod for it to contain the tokens
		for (TSharedRef<IPlugin> Mod : Mods) {
			// check each token in mod name
			if (PluginMatchesSearchTokens(Mod.Get(), FilterTokens)) {
				FilteredMods.Add(Mod);
			}
		}
	}

	ModList->RequestListRefresh();
}

FString SAlpakitModEntryList::GetLastFilter() const {
	return LastFilter;
}

void SAlpakitModEntryList::SetShowEngine(bool bInShowEngine) {
	bShowEngine = bInShowEngine;
	LoadMods();
}

FReply SAlpakitModEntryList::PackageAllMods() {
	TSharedPtr<SAlpakitModEntry> first;
	TArray<TSharedPtr<SAlpakitModEntry>> nextEntries;

	UE_LOG(LogTemp, Display, TEXT("Alpakit All!"))

	for (auto mod : FilteredMods) {
		UE_LOG(LogTemp, Display, TEXT("Collecting Plugin %s!"), *mod->GetName())

		auto tableRow = ModList->WidgetFromItem(mod);
		if (!tableRow.IsValid()) {
			UE_LOG(LogTemp, Display, TEXT("TableRow not found!"))

			continue;
		}

		auto modEntry = StaticCastSharedPtr<SAlpakitModEntry>(tableRow->GetContent());
		if (!modEntry.IsValid()) {
			UE_LOG(LogTemp, Display, TEXT("TableRow content is not valid!"))

			continue;
		}

		if(!modEntry->IsSelected()) {
			UE_LOG(LogTemp, Display, TEXT("Plugin is not selected: %s"), * mod->GetName());

			continue;
		}

		if (!first) {
			first = modEntry.ToSharedRef();
		} else {
			nextEntries.Add(modEntry.ToSharedRef());
		}
	}

	if (first) {
		first->PackageMod(nextEntries);
	}

	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
