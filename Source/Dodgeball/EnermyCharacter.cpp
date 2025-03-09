// Fill out your copyright notice in the Description page of Project Settings.


#include "EnermyCharacter.h"
#include "Engine/World.h"

// Sets default values
AEnermyCharacter::AEnermyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnermyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnermyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnermyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnermyCharacter::LookAtActor(AActor* TargetActor)
{
}

bool AEnermyCharacter::CanSeeActor(const AActor* TargetActor) const
{
	if (TargetActor == nullptr)
	{
		return false;
	}

	// 라인 트레이스 결과 저장
	FHitResult Hit;

	// 라인 트레이스 시작 위치
	FVector Start = GetActorLocation();

	// 라인 트레이스 끝 위치
	FVector End = TargetActor->GetActorLocation();

	// 시야 판단을 위한 트레이스 채널
	ECollisionChannel Channel = ECollisionChannel::ECC_Visibility;

	FCollisionQueryParams QueryParams;

	// 라인 트레이스를 실행하는 액터 무시
	QueryParams.AddIgnoredActor(this);

	// 타겟 액터 무시
	QueryParams.AddIgnoredActor(TargetActor);

	// 라인 트레이스 실행
	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, Channel, QueryParams);

	return Hit.bBlockingHit;
}

