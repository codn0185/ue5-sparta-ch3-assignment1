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
	float RotatingSpeedYaw;  // z축 기준 회전 속도 (초 당 회전 각도)
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Properties")
	float RotationTimerRate;  // 회전 타이머 주기
	UPROPERTY()
	FTimerHandle RotationTimerHandle;  // 회전 타이머 핸들

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Actions")
	virtual void RotateActor();
};
