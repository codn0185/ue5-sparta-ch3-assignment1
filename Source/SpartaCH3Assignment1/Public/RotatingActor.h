#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"

#include "RotatingActor.generated.h"

UCLASS()
class SPARTACH3ASSIGNMENT1_API ARotatingActor : public AActor
{
	GENERATED_BODY()

  public:
	ARotatingActor();

  protected:
	// Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;  // 루트 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMeshComp;  // 스태틱 메시 컴포넌트

	// Properties
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Properties")
	FRotator RotatingSpeed;  // 회전 속도 (각 방향 별 초 당 회전 각도)

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
