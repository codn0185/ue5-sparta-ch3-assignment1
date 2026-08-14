#include "BlinkActor.h"

ABlinkActor::ABlinkActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	ShowDuration = 2.0f;
	HideDuration = 3.0f;
	InitialDelay = 0.001f;
}

void ABlinkActor::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(
		BlinkTimerHandle,
		this,
		&ABlinkActor::OnShowTimerFinished,
		InitialDelay,
		false);
}

void ABlinkActor::ShowActor()
{
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
}

void ABlinkActor::HideActor()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}

void ABlinkActor::OnShowTimerFinished()
{
	HideActor();
	GetWorldTimerManager().SetTimer(
		BlinkTimerHandle,
		this,
		&ABlinkActor::OnHideTimerFinished,
		HideDuration,
		false);
}

void ABlinkActor::OnHideTimerFinished()
{
	ShowActor();
	GetWorldTimerManager().SetTimer(
		BlinkTimerHandle,
		this,
		&ABlinkActor::OnShowTimerFinished,
		ShowDuration,
		false);
}

void ABlinkActor::Initialize(const float& InShowDuration, const float& InHideDuration, const float& InInitialDelay)
{
	ShowDuration = FMath::Max(InShowDuration, 0.001f);
	HideDuration = FMath::Max(InHideDuration, 0.001f);
	InitialDelay = FMath::Max(InInitialDelay, 0.001f);

	GetWorldTimerManager().ClearTimer(BlinkTimerHandle);

	GetWorldTimerManager().SetTimer(
		BlinkTimerHandle,
		this,
		&ABlinkActor::OnShowTimerFinished,
		InitialDelay,
		false);
}
