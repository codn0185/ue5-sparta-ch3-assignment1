#include "MovingPlatformActor.h"

AMovingPlatformActor::AMovingPlatformActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	MoveSpeed = 10.0f;
	MaxRange = 100.0f;
	bDirection = true;
}

void AMovingPlatformActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	EndLocation = StartLocation + FVector(MaxRange, 0.0f, 0.0f);
}

void AMovingPlatformActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bDirection)
	{
		FVector NewLocation = FMath::VInterpConstantTo(GetActorLocation(), EndLocation, DeltaTime, MoveSpeed);
		SetActorLocation(NewLocation);
		if (NewLocation.Equals(EndLocation))
		{
			bDirection = false;
		}
	}
	else
	{
		FVector NewLocation = FMath::VInterpConstantTo(GetActorLocation(), StartLocation, DeltaTime, MoveSpeed);
		SetActorLocation(NewLocation);
		if (NewLocation.Equals(StartLocation))
		{
			bDirection = true;
		}
	}
}
