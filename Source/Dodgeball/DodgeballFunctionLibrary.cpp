// Fill out your copyright notice in the Description page of Project Settings.


#include "DodgeballFunctionLibrary.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "CollisionQueryParams.h"


bool UDodgeballFunctionLibrary::CanSeeActor(const UWorld* World, FVector Location, const AActor* TargetActor, TArray<const AActor*> IgnoreActors)
{
	if (TargetActor == nullptr)
	{
		return false;
	}

	// 라인 트레이스 결과 저장
	FHitResult Hit;

	// 라인 트레이스 시작 위치
	FVector Start = Location;

	// 라인 트레이스 끝 위치
	FVector End = TargetActor->GetActorLocation();

	// 시야 판단을 위한 트레이스 채널
	ECollisionChannel Channel = ECollisionChannel::ECC_GameTraceChannel1;

	FCollisionQueryParams QueryParams;

	// 지정한 액터들을 무시
	QueryParams.AddIgnoredActors(IgnoreActors);

	// 라인 트레이스 실행
	World->LineTraceSingleByChannel(Hit, Start, End, Channel, QueryParams);

	// 라인 트레이스 시각화
	DrawDebugLine(World, Start, End, FColor::Red);

	// 스윕 트레이스에서 사용되는 모형의 회전
	//FQuat Rotation = FQuat::Identity;

	// 스윕 트레이스에서 사용하는 객체의 모형
	//FCollisionShape Shape = FCollisionShape::MakeBox(FVector(20.f, 20.f, 20.f));

	// 스윕 트레이스 실행
	//World->SweepSingleByChannel(Hit, Start, End, Rotation, Channel, Shape);

	return !Hit.bBlockingHit;
}
