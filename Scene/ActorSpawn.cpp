#include "UObject/ConstructorHelpers.h"
#include "MyStaticMeshActor.h"
#include "MySceneComponent.h"

UMySceneComponent::UMySceneComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMySceneComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UMySceneComponent::SpawnSphere()
{
	UWorld* world = GetWorld();
	if (!world) {
		UE_LOG(LogTemp, Warning, TEXT("Can't get world!"));
		return;
	}

	FRotator rotator;
	FVector spawnLocation(540.0f, 0.0f, 300.0f);
	FActorSpawnParameters spawnParams;

	world->SpawnActor<AMyStaticMeshActor>(AMyStaticMeshActor::StaticClass(),
		spawnLocation,
		rotator,
		spawnParams);
}

void UMySceneComponent::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	static float accu = 0.0f;
	accu += DeltaTime;

	if (accu > 1.0f) {
		UE_LOG(LogTemp, Warning, TEXT("Spawning sphere..."));
		accu = 0.0f;
		SpawnSphere();
	}
}

