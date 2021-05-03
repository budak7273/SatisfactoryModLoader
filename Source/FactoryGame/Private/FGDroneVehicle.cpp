// This file has been automatically generated by the Unreal Header Implementation tool

#include "FGDroneVehicle.h"

#ifdef DEBUG_DRONES
void UFGDroneAction::DisplayDebugInformation(){ }
#endif 
UFGDroneAction::UFGDroneAction(){ }
void UFGDroneAction::PostLoadGame_Implementation(int32 saveVersion, int32 gameVersion){ }
bool UFGDroneAction::NeedTransform_Implementation(){ return bool(); }
bool UFGDroneAction::ShouldSave_Implementation() const{ return bool(); }
void UFGDroneAction::PushAction(UFGDroneAction* pAction){ }
#ifdef DEBUG_DRONES
void UFGDroneAction_Timed::DisplayDebugInformation(){ }
#endif 
UFGDroneAction_Timed::UFGDroneAction_Timed(){ }
void UFGDroneAction_Timed::Tick(float dt){ }
bool UFGDroneAction_Timed::IsDone() const{ return bool(); }
#ifdef DEBUG_DRONES
void UFGDroneAction_TraversePath::DisplayDebugInformation(){ }
#endif 
UFGDroneAction_TraversePath::UFGDroneAction_TraversePath(){ }
void UFGDroneAction_TraversePath::SetPath(const TArray<FVector>& Path, EDroneFlyingMode FlyingMode, bool StopAtDestination){ }
void UFGDroneAction_TraversePath::Begin(){ }
void UFGDroneAction_TraversePath::Tick(float dt){ }
void UFGDroneAction_TraversePath::ReceiveActionEvent(EDroneActionEvent ActionEvent, void* EventData){ }
bool UFGDroneAction_TraversePath::IsDone() const{ return bool(); }
void UFGDroneAction_TraversePath::GotoNextDestination(){ }
#ifdef DEBUG_DRONES
void UFGDroneAction_RequestDocking::DisplayDebugInformation(){ }
#endif 
UFGDroneAction_RequestDocking::UFGDroneAction_RequestDocking() : Super() {
	this->mQueuePosition = -1;
}
void UFGDroneAction_RequestDocking::SetStation( AFGBuildableDroneStation* Station, bool ShouldTransferItems){ }
void UFGDroneAction_RequestDocking::Begin(){ }
void UFGDroneAction_RequestDocking::End(){ }
void UFGDroneAction_RequestDocking::MoveToDesignatedQueuePosition(EDroneFlyingMode FlyingMode){ }
void UFGDroneAction_RequestDocking::Tick(float dt){ }
void UFGDroneAction_RequestDocking::ReceiveActionEvent(EDroneActionEvent ActionEvent, void* EventData){ }
bool UFGDroneAction_RequestDocking::IsDone() const{ return bool(); }
UFGDroneAction_DockingSequence::UFGDroneAction_DockingSequence(){ }
void UFGDroneAction_DockingSequence::SetStation( AFGBuildableDroneStation* Station, bool ShouldTransferItems){ }
void UFGDroneAction_DockingSequence::Begin(){ }
void UFGDroneAction_DockingSequence::End(){ }
float UFGDroneAction_DockingSequence::GetActionDuration() const{ return float(); }
UFGDroneAction_TakeoffSequence::UFGDroneAction_TakeoffSequence(){ }
void UFGDroneAction_TakeoffSequence::SetStation( AFGBuildableDroneStation* Station){ }
void UFGDroneAction_TakeoffSequence::Begin(){ }
void UFGDroneAction_TakeoffSequence::End(){ }
float UFGDroneAction_TakeoffSequence::GetActionDuration() const{ return float(); }
void UFGDroneAction_TakeoffSequence::ReceiveActionEvent(EDroneActionEvent ActionEvent, void* EventData){ }
void UFGDroneAction_TravelStartSequence::SetDestination(const FVector& Destination){ }
void UFGDroneAction_TravelStartSequence::Begin(){ }
void UFGDroneAction_TravelStartSequence::End(){ }
float UFGDroneAction_TravelStartSequence::GetActionDuration() const{ return float(); }
AFGDroneVehicle::AFGDroneVehicle() : Super() {
	this->mInventorySize = 20;
	this->mBatteryStorageSize = 1;
	this->mDisabledByWaterLocations.SetNum(1); this->mDisabledByWaterLocations[0].X = 0; this->mDisabledByWaterLocations[0].Y = 0; this->mDisabledByWaterLocations[0].Z = 0;
	this->mSignificanceRange = 20000;
	this->mSimulationDistance = 20000;
	this->mShouldAttachDriver = true;
}
void AFGDroneVehicle::BeginPlay(){ }
void AFGDroneVehicle::Tick(float DeltaTime){ }
void AFGDroneVehicle::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const{ }
bool AFGDroneVehicle::IsUseable_Implementation() const{ return bool(); }
void AFGDroneVehicle::Dismantle_Implementation(){ }
void AFGDroneVehicle::OnSimulationChanged(){ }
void AFGDroneVehicle::GainedSignificance_Implementation(){ }
void AFGDroneVehicle::LostSignificance_Implementation(){ }
void AFGDroneVehicle::PostLoadGame_Implementation(int32 saveVersion, int32 gameVersion){ }
void AFGDroneVehicle::NotifyPairedStationUpdated( AFGBuildableDroneStation* NewPairedStation){ }
void AFGDroneVehicle::OnUndocked(){ }
void AFGDroneVehicle::OnDockedStationDestroyed(){ }
void AFGDroneVehicle::OnBeginLoadVehicle_Implementation(){ }
void AFGDroneVehicle::OnBeginUnloadVehicle_Implementation(){ }
void AFGDroneVehicle::OnTransferComplete_Implementation(){ }
TArray<FVector> AFGDroneVehicle::GeneratePathToDestination(const FVector& CurrentLocation, const FVector& Destination, UWorld* World){ return TArray<FVector>(); }
void AFGDroneVehicle::SetCurrentDestination(const FVector& NewDestination, EDroneFlyingMode FlyingMode, bool StopAtDestination){ }
void AFGDroneVehicle::StopMoving(){ }
void AFGDroneVehicle::BeginDocking( AFGBuildableDroneStation* station){ }
void AFGDroneVehicle::UpdateDockingQueuePosition(int NewPosition){ }
float AFGDroneVehicle::GetSpeedForFlyingMode(EDroneFlyingMode Mode) const{ return float(); }
float AFGDroneVehicle::GetStoppingDistanceForFlyingMode(EDroneFlyingMode Mode) const{ return float(); }
float AFGDroneVehicle::GetTimeSinceDockingStateChanged() const{ return float(); }
void AFGDroneVehicle::SetHomeStation( AFGBuildableDroneStation* station){ }
bool AFGDroneVehicle::GrabRequiredBatteriesForTrip( AFGBuildableDroneStation* FromStation,  AFGBuildableDroneStation* ToStation, bool AllowTravelWithoutCost){ return bool(); }
bool AFGDroneVehicle::TravelToStation( AFGBuildableDroneStation* station, bool ShouldTransferItems){ return bool(); }
void AFGDroneVehicle::BeginNewTrip( AFGBuildableDroneStation* Station){ }
void AFGDroneVehicle::EndCurrentTrip(bool Completed){ }
void AFGDroneVehicle::SetFacingDirection(const FVector& Direction){ }
void AFGDroneVehicle::StartDockingSequence_Implementation( AFGBuildableDroneStation* Station){ }
void AFGDroneVehicle::EndDockingSequence_Implementation( AFGBuildableDroneStation* Station, bool ShouldTransferItems){ }
void AFGDroneVehicle::StartTakeoffSequence_Implementation( AFGBuildableDroneStation* Station){ }
void AFGDroneVehicle::EndTakeoffSequence_Implementation( AFGBuildableDroneStation* Station){ }
void AFGDroneVehicle::StartTravelStartSequence_Implementation(){ }
void AFGDroneVehicle::EndTravelStartSequence_Implementation(){ }
void AFGDroneVehicle::OnRep_IsBraking(){ }
void AFGDroneVehicle::OnRep_FlyingMode(){ }
void AFGDroneVehicle::OnRep_DockingState(){ }
void AFGDroneVehicle::OnRep_DockedStation(){ }
void AFGDroneVehicle::OnSignificanceUpdate(){ }
void AFGDroneVehicle::ClearAllActions(bool KeepCurrentAction){ }
void AFGDroneVehicle::SetNewFlyingMode(EDroneFlyingMode Mode){ }
void AFGDroneVehicle::SetDockingState(EDroneDockingState State){ }
bool AFGDroneVehicle::ConsumeBatteriesForPower(float PowerRequirement){ return bool(); }
void AFGDroneVehicle::CalculateInventoryPotentialPower(){ }
