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

	// Properties
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Properties")
	FVector StartLocation;  // 시작 위치
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Properties")
	FVector EndLocation;  // 종료 위치
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Properties")
	float MoveSpeed;  // 이동 속도
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Properties")
	float MaxRange;  // 왕복 이동 거리 (x축 방향)

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
