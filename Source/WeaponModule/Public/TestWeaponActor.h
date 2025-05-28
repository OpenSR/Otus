#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestWeaponActor.generated.h"

UCLASS()
class WEAPONMODULE_API ATestWeaponActor : public AActor
{
	GENERATED_BODY()

public:
	ATestWeaponActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gun")
	UStaticMeshComponent* GunMesh;
};