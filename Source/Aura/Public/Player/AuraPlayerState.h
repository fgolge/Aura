// Copyright M. Fatih Golge

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "AuraPlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAuraPlayerState();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	/**
	 * Variables
	 */

	UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_Level)
	int32 Level = 1;

	/**
	 * Functions
	 */

	UFUNCTION()
	void OnRep_Level(int32 OldLevel);

protected:
	/**
	 * Variables
	 */

	/* Ability System */
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

public:
	/**
	 * Functions
	 */

	/* Ability System */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }
	FORCEINLINE int32 GetPlayerLevel() const { return Level; }
};
