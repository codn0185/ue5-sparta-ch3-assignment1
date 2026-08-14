#include "RotatingActor.h"

ARotatingActor::ARotatingActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	RotatingSpeed.Yaw = 30.0f;
	RotationTimerRate = 0.02f;
}

void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(
		RotationTimerHandle,
		this,
		&ARotatingActor::RotateActor,
		RotationTimerRate,
		true);
}

void ARotatingActor::RotateActor()
{
	AddActorLocalRotation(RotatingSpeed * RotationTimerRate);
}
