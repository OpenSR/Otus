#include "TestWeaponActor.h"
#include <string>
#include "Components/StaticMeshComponent.h"

ATestWeaponActor::ATestWeaponActor()
{
	PrimaryActorTick.bCanEverTick = false;
	const std::string OBJIdStr = "WeaponMesh" + std::to_string(GetUniqueID());
	const FName UobjId = FName(UTF8_TO_TCHAR(OBJIdStr.c_str()));
	GunMesh = CreateDefaultSubobject<UStaticMeshComponent>(UobjId);
	RootComponent = GunMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Weapons_Free/Meshes/SM_axe_001.SM_axe_001"));
	if (MeshAsset.Succeeded())
	{
		GunMesh->SetStaticMesh(MeshAsset.Object);
	}
}