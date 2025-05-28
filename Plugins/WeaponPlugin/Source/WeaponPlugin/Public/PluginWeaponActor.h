#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PluginWeaponActor.generated.h"

UCLASS()
class WEAPONPLUGIN_API APluginWeaponActor : public AActor
{
	GENERATED_BODY()

public:
	APluginWeaponActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gun")
	UStaticMeshComponent* GunMesh;
};