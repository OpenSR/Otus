#include "TestWeaponActor.h"
#include "Components/StaticMeshComponent.h"

ATestWeaponActor::ATestWeaponActor()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}