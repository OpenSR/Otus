#include "PluginWeaponActor.h"
#include "Components/StaticMeshComponent.h"

APluginWeaponActor::APluginWeaponActor()
{
	PrimaryActorTick.bCanEverTick = false;
	RootComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}