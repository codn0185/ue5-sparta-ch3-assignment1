#include "MovingPlatformActor.h"

AMovingPlatformActor::AMovingPlatformActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	MoveSpeed = 10.0f;
	MaxRange = 100.0f;
	MovingTimerRate = 0.02f;
}

void AMovingPlatformActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	EndLocation = StartLocation + FVector(MaxRange, 0.0f, 0.0f);

	GetWorld()->GetTimerManager().SetTimer(
		MovingTimerHandle,
		this,
		&AMovingPlatformActor::MoveActor,
		MovingTimerRate,
		true);
}

void AMovingPlatformActor::MoveActor()
{
	FVector NewLocation = FMath::VInterpConstantTo(GetActorLocation(), EndLocation, MovingTimerRate, MoveSpeed);
	SetActorLocation(NewLocation);
	if (NewLocation.Equals(EndLocation))
	{
		std::swap(StartLocation, EndLocation);
	}
}
