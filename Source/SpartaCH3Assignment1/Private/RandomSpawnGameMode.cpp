#include "RandomSpawnGameMode.h"

#include "BlinkActor.h"
#include "MovingPlatformActor.h"
#include "RotatingActor.h"

ARandomSpawnGameMode::ARandomSpawnGameMode()
{
	SpawnCount = 5;
}

void ARandomSpawnGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (!SpawnClassArray.IsEmpty())
	{
		for (int i = 0; i < SpawnCount; i++)
		{
			AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(SpawnClassArray[FMath::RandRange(0, SpawnClassArray.Num() - 1)],
																  GetRandomLocation(),
																  FRotator::ZeroRotator);

			if (AMovingPlatformActor* MovingPlatformActor = Cast<AMovingPlatformActor>(SpawnedActor))
			{
				MovingPlatformActor->Initialize(FMath::RandRange(1.0f, 20.0f),
												FVector(FMath::RandRange(-100.0f, 100.0f),
														FMath::RandRange(-100.0f, 100.0f),
														FMath::RandRange(-100.0f, 100.0f)));
			}
			else if (ARotatingActor* RotatingActor = Cast<ARotatingActor>(SpawnedActor))
			{
				RotatingActor->Initialize(FRotator(FMath::RandRange(-180.0f, 180.0f),
												   FMath::RandRange(-180.0f, 180.0f),
												   FMath::RandRange(-180.0f, 180.0f)));
			}
			else if (ABlinkActor* BlinkActor = Cast<ABlinkActor>(SpawnedActor))
			{
				BlinkActor->Initialize(FMath::RandRange(1.0f, 10.0f),
									   FMath::RandRange(1.0f, 10.0f),
									   FMath::RandRange(0.02f, 2.0f));
			}
		}
	}
}

FVector ARandomSpawnGameMode::GetRandomLocation()
{
	float X = FMath::RandRange(-1000, 1000);
	float Y = FMath::RandRange(-1000, 1000);
	float Z = FMath::RandRange(0, 500);
	return FVector(X, Y, Z);
}
