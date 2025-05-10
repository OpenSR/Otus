#include "MyTestActor.h"

AMyTestActor::AMyTestActor(): TargetActor(nullptr)
{
	PrimaryActorTick.bCanEverTick = false;
}

FVector AMyTestActor::GetTrackedActorLocation() const
{
	return TargetActor ? TargetActor->GetActorLocation() : FVector::ZeroVector;
}
