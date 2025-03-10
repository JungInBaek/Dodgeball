// Fill out your copyright notice in the Description page of Project Settings.


#include "EnermyCharacter.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"


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

	// 현재 플레이어가 제어하는 캐릭터
	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);

	// 매 프레임 플레이어 캐릭터를 바라본다
	LookAtActor(PlayerCharacter);
}

// Called to bind functionality to input
void AEnermyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnermyCharacter::LookAtActor(AActor* TargetActor)
{
	if (TargetActor == nullptr)
	{
		return;
	}

	if (CanSeeActor(TargetActor))
	{
		FVector Start = GetActorLocation();
		FVector End = TargetActor->GetActorLocation();

		// 시작 지점에서 끝 지점을 바라보는 데 필요한 회전 계산
		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(Start, End);

		// 적의 회전을 구한 회전 값으로 설정
		SetActorRotation(LookAtRotation);
	}
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

	// 라인 트레이스 시각화
	DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	return !Hit.bBlockingHit;
}

