#include "MovingPlatformActor.h"

AMovingPlatformActor::AMovingPlatformActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	MoveSpeed = 10.0f;
	MoveOffset.X = 100.0f;
}

void AMovingPlatformActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	EndLocation = StartLocation + MoveOffset;
}

void AMovingPlatformActor::Tick(float DeltaTime)
{
	FVector NewLocation = FMath::VInterpConstantTo(GetActorLocation(), EndLocation, DeltaTime, MoveSpeed);
	SetActorLocation(NewLocation);
	if (NewLocation.Equals(EndLocation))
	{
		std::swap(StartLocation, EndLocation);
	}
}
