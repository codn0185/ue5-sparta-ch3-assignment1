#include "RotatingActor.h"

ARotatingActor::ARotatingActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	RotatingSpeedYaw = 15.0f;
	RotationTimerRate = 0.2f;
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
	AddActorLocalRotation(FRotator(0.0f, RotatingSpeedYaw * RotationTimerRate, 0.0f));
}
