// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}

 float ATank::TakeDamage
(
	float DamageAmount,
	struct FDamageEvent const & DamageEvent,
	class AController * EventInstigator,
	AActor * DamageCauser
)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);
	CurrentHealth -= DamageToApply ;
	UE_LOG(LogTemp, Warning, TEXT(" DamageAmount = %f , DamageToApply = %i , CurrentHealth = %i"),DamageAmount, DamageToApply, CurrentHealth);
	if(CurrentHealth <=0)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Tank blew up"));
		OnDeath.Broadcast();
	}
	return DamageToApply;
}

float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / float(StartingHealth) ;
}