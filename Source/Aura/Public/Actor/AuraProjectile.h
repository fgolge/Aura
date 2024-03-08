// Copyright M. Fatih Golge

#pragma once

#include "CoreMinimal.h"
#include "AuraAbilityTypes.h"
#include "GameFramework/Actor.h"
#include "AuraProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UNiagaraSystem;

UCLASS()
class AURA_API AAuraProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AAuraProjectile();

protected:
	virtual void BeginPlay() override;
	virtual void Destroyed() override;
	void OnHit();
	virtual void LifeSpanExpired() override;

private:
	/**
	 * Variables
	 */

	/* Default */

	UPROPERTY(EditDefaultsOnly)
	float LifeSpan = 15.f;

	/* Components */
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;

	UPROPERTY()
	TObjectPtr<UAudioComponent> LoopingSoundComponent;

	/**
	 * Functions
	 */

	/* Collision */

	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	bool bHit = false;

	/* SFX and VFX */

	UPROPERTY(EditAnywhere)
	TObjectPtr<UNiagaraSystem> ImpactEffect;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USoundBase> ImpactSound;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USoundBase> LoopingSound;

protected:
	/**
	 * Variables
	 */

	/**
	 * Functions
	 */
	
public:
	/**
	 * Variables
	 */

	/* Components */
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;

	/* Gameplay Effects */

	UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpaw = true))
	FDamageEffectParams DamageEffectParams;

	/**
	 * Functions
	 */
	

};
