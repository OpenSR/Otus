#include "PluginWeaponActor.h"
#include "Components/StaticMeshComponent.h"
#include <string>

APluginWeaponActor::APluginWeaponActor()
{
	PrimaryActorTick.bCanEverTick = false;
	const std::string OBJIdStr = "PluginWeaponMesh" + std::to_string(GetUniqueID());
	const FName UobjId = FName(UTF8_TO_TCHAR(OBJIdStr.c_str()));
	GunMesh = CreateDefaultSubobject<UStaticMeshComponent>(UobjId);
	RootComponent = GunMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Weapons_Free/Meshes/SM_knife_001.SM_knife_001"));
	if (MeshAsset.Succeeded())
	{
		GunMesh->SetStaticMesh(MeshAsset.Object);
	}
}