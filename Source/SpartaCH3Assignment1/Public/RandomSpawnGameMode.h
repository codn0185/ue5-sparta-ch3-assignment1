#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameMode.h"

#include "RandomSpawnGameMode.generated.h"

UCLASS()
class SPARTACH3ASSIGNMENT1_API ARandomSpawnGameMode : public AGameMode
{
	GENERATED_BODY()

  public:
	ARandomSpawnGameMode();

  protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Properties")
	TArray<TSubclassOf<AActor>> SpawnClassArray;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Properties", meta = (ClampMin = "0"))
	int SpawnCount;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Actions")
	FVector GetRandomLocation();
};
