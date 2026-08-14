#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"

#include "BlinkActor.generated.h"

UCLASS()
class SPARTACH3ASSIGNMENT1_API ABlinkActor : public AActor
{
	GENERATED_BODY()

  public:
	ABlinkActor();

  protected:
	// Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;  // 루트 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMeshComp;  // 스태틱 메시 컴포넌트

	// Properties
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Properties", meta = (ClampMin = "0.001", UIMin = "0.001"))
	float ShowDuration;  // 활성화된 시간
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Properties", meta = (ClampMin = "0.001", UIMin = "0.001"))
	float HideDuration;  // 비활성화된 시간
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Properties")
	FTimerHandle BlinkTimerHandle;  // 타이머 핸들
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Properties", meta = (ClampMin = "0.001", UIMin = "0.001"))
	float InitialDelay;  // 초기 지연 시간

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Actions")
	virtual void ShowActor();
	UFUNCTION(BlueprintCallable, Category = "Actions")
	virtual void HideActor();
	UFUNCTION(BlueprintCallable, Category = "Actions")
	virtual void OnShowTimerFinished();
	UFUNCTION(BlueprintCallable, Category = "Actions")
	virtual void OnHideTimerFinished();
};
