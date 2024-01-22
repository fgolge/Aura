// Copyright M. Fatih Golge

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/Data/CharacterClassInfo.h"
#include "AuraEnemy.generated.h"

class UWidgetComponent;
/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();

protected:
	virtual void BeginPlay() override;

protected:
	/**
	 * Variables
	 */

	/* Ability System */

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterClassDefaults")
	int32 Level = 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterClassDefaults")
	ECharacterClass CharacterClass = ECharacterClass::Warrior;

	/* UI */

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;

	/**
	 * Functions
	 */

	/* Ability System */
	virtual void InitAbilityActorInfo() override;
	virtual void InitializeDefaultAttributes() const override;

public:
	/**
	 * Variables
	 */

	/* Combat */

	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	bool bHitReacting = false;

	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	float BaseWalkSpeed = 250.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat")
	float LifeSpan = 5.f;

	/* UI */

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnHealthChanged;
	
	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxHealthChanged;
	
	/**
	 * Functions
	 */

	/* Ability System */
	void HitReactTagChanged(const FGameplayTag CallbackTag, int32 NewCount);

	/* Enemy Interface */
	virtual void HighlightActor() override;
	virtual void UnhighlightActor() override;

	/* Combat Interface */
	virtual int32 GetPlayerLevel() override;
	virtual void Die() override;
};
