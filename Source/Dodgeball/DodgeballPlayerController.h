// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DodgeballPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class DODGEBALL_API ADodgeballPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	void ShowRestartWidget();
	void HideRestartWidget();
	void UpdateHealthPercent(float HealthPercent);
	
public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class URestartWidget> BP_RestartWidget;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UHUDWidget> BP_HUDWidget;

private:
	UPROPERTY()
	class URestartWidget* RestartWidget;

	UPROPERTY()
	class UHUDWidget* HUDWidget;
};
