// Copyright M. Fatih Golge

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

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
	 * Functions
	 */

	/* Ability System */
	virtual void InitAbilityActorInfo() override;

public:
	/**
	 * Variables
	 */

	/**
	 * Functions
	 */

	/* Enemy Interface */
	virtual void HighlightActor() override;
	virtual void UnhighlightActor() override;
};
