#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTestActor.generated.h"

UCLASS()
class OTUS_API AMyTestActor : public AActor
{
	GENERATED_BODY()

public:
	AMyTestActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Test")
	AActor* TargetActor;

	UFUNCTION(BlueprintCallable, Category="Test")
	FVector GetTrackedActorLocation() const;
};