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

public:
	/**
	 * Variables
	 */

	/**
	 * Functions
	 */

	/* UI */
	virtual void HighlightActor() override;
	virtual void UnhighlightActor() override;
};
