// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"

#include "MovingPlatformActor.generated.h"

UCLASS()
class SPARTACH3ASSIGNMENT1_API AMovingPlatformActor : public AActor
{
	GENERATED_BODY()

  public:
	AMovingPlatformActor();

  protected:
	// Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;  // 루트 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMeshComp;  // 스태틱 메시 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* StartPointComp;  // 시작 위치 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* EndPointComp;  // 종료 위치 기즈모 컴포넌트

	// Properties
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Properties", meta = (ClampMin = "0.001", UIMin = "0.001"))
	float MoveSpeed;  // 이동 속도 (초 당 이동거리)
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Properties")
	bool bMovingDirection;  // 이동 방향 (true: Start->End / false: End->Start)

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

  public:
	UFUNCTION(BlueprintCallable, Category = "Actions")
	virtual void Initialize(const float& InMoveSpeed, const FVector& InMoveOffset);
};
