#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Otus/MyTestActor.h"
#include "Tests/AutomationEditorCommon.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyTestActorLocationTest,
                                 "Project.MyTestActor.ReturnsCorrectLocation",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FMyTestActorLocationTest::RunTest(const FString& Parameters)
{
	UWorld* World = GEditor->GetEditorWorldContext().World();
	if (!World)
	{
		AddError(TEXT("Could not load world"));
		return false;
	}

	TArray<AActor*> FoundTestActors;
	UGameplayStatics::GetAllActorsOfClass(World, AMyTestActor::StaticClass(), FoundTestActors);

	TestTrue(TEXT("Found at least one MyTestActor"), FoundTestActors.Num() > 0);
	AMyTestActor* MyActor = Cast<AMyTestActor>(FoundTestActors[0]);

	TestNotNull(TEXT("MyActor TargetActor is NULL"), MyActor->TargetActor);

	FVector Expected = MyActor->TargetActor->GetActorLocation();
	FVector Actual = MyActor->GetTrackedActorLocation();

	TestEqual(TEXT("Tracked location matches target"), Actual, Expected);

	return true;
}

#endif