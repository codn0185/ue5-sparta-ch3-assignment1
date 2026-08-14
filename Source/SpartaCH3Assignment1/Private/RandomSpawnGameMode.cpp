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
			GetWorld()->SpawnActor<AActor>(
				SpawnClassArray[FMath::RandRange(0, SpawnClassArray.Num() - 1)],
				GetRandomLocation(),
				FRotator::ZeroRotator);
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
