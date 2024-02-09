// Copyright M. Fatih Golge

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameplayTagContainer.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class UDamageTextComponent;
struct FGameplayTag;
class UAuraInputConfig;
class UInputAction;
class UInputMappingContext;
class IEnemyInterface;
class UAuraAbilitySystemComponent;
class USplineComponent;

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAuraPlayerController();
	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	/**
	 * Variables
	 */

	/* Input */
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> ShiftAction;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UAuraInputConfig> InputConfig;

	bool bShiftKeyDown = false;

	/* Movement */
	FVector CachedDestination = FVector::ZeroVector;
	float FollowTime = 0.f;
	float ShortPressThreshold = 0.5f;
	bool bAutoRunning = false;
	bool bTargeting = false;

	UPROPERTY(EditDefaultsOnly)
	float AutoRunAcceptanceRadius = 50.f;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplineComponent> Spline;

	/* Gameplay Ability System */
	UPROPERTY()
	TObjectPtr<UAuraAbilitySystemComponent> AuraAbilitySystemComponent;

	/* UI */
	FHitResult CursorHit;
	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UDamageTextComponent> DamageTextComponentClass;

	/**
	 * Functions
	 */

	/* Input Callbacks */
	void Move(const FInputActionValue& InputActionValue);
	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);
	void ShiftPressed() { bShiftKeyDown = true; };
	void ShiftReleased() { bShiftKeyDown = false; };

	/* Movement */
	void AutoRun();

	/* Gameplay Ability System */
	UAuraAbilitySystemComponent* GetASC();

	/* UI */
	void CursorTrace();
	
public:
	/**
	 * Functions
	 */

	/* UI */

	UFUNCTION(Client, Reliable)
	void ShowDamageNumber(ACharacter* TargetCharacter, float DamageAmount, bool bCriticalHit, bool bBlockedHit);
};
