#include "RotatingActor.h"

ARotatingActor::ARotatingActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	RotatingSpeed.Yaw = 30.0f;
}

void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();
}

void ARotatingActor::Tick(float DeltaTime)
{
	AddActorLocalRotation(RotatingSpeed * DeltaTime);
}
