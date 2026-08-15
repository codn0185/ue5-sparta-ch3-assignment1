#include "MovingPlatformActor.h"

AMovingPlatformActor::AMovingPlatformActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	StartPointComp = CreateDefaultSubobject<USceneComponent>(TEXT("StartPoint"));
	StartPointComp->SetupAttachment(SceneRoot);
	StartPointComp->SetRelativeLocation(FVector::ZeroVector);

	EndPointComp = CreateDefaultSubobject<USceneComponent>(TEXT("EndPoint"));
	EndPointComp->SetupAttachment(SceneRoot);
	EndPointComp->SetRelativeLocation(FVector(100.0f, 0.0f, 0.0f));

	MoveSpeed = 10.0f;
	bMovingDirection = true;
}

void AMovingPlatformActor::BeginPlay()
{
	Super::BeginPlay();
}

void AMovingPlatformActor::Tick(float DeltaTime)
{
	const FVector& TargetLocation = bMovingDirection ? EndPointComp->GetRelativeLocation() : StartPointComp->GetRelativeLocation();  // 목표 지점
	const FVector& NewLocation = FMath::VInterpConstantTo(StaticMeshComp->GetRelativeLocation(), TargetLocation, DeltaTime, MoveSpeed);
	StaticMeshComp->SetRelativeLocation(NewLocation);

	if (bMovingDirection && NewLocation.Equals(EndPointComp->GetRelativeLocation()))  // EndPointComp 도달
	{
		bMovingDirection = false;
	}
	else if (!bMovingDirection && NewLocation.Equals(StartPointComp->GetRelativeLocation()))  // StartPointComp 도달
	{
		bMovingDirection = true;
	}
}

void AMovingPlatformActor::Initialize(const float& InMoveSpeed, const FVector& InRelativeStartPoint, const FVector& InRelativeEndPoint, const bool& bInMovingDirection)
{
	MoveSpeed = FMath::Max(InMoveSpeed, 0.001f);
	StartPointComp->SetRelativeLocation(InRelativeStartPoint);
	EndPointComp->SetRelativeLocation(InRelativeEndPoint);
	bMovingDirection = bInMovingDirection;
}
