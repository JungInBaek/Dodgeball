// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnermyCharacter.generated.h"

UCLASS()
class DODGEBALL_API AEnermyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnermyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	bool LookAtActor(AActor* TargetActor);

	bool CanSeeActor(const AActor* TargetActor) const;

	void ThrowDodgeball();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = LookAt, meta = (AllowPrivateAccess = "true"))
	USceneComponent* SightSource;

protected:
	// 이번 프레임에 플레이어를 볼 수 있는지 여부
	bool bCanSeePlayer;

	// 이전 프레임에 플레이어를 볼 수 있었는지 여부
	bool bPreviousCanSeePlayer;

	FTimerHandle ThrowTimerHandle;

	float ThrowingInterval = 2.f;

	float ThrowingDelay = 0.5f;

public:
	// Dodgeball 오브젝트를 생성하는 데 사용하는 클래스
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Dodgeball)
	TSubclassOf<class ADodgeballProjectile> DodgeballClass;
};
