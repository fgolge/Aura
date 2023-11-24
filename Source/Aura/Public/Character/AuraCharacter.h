// Copyright M. Fatih Golge

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

protected:
	/**
	 * Functions
	 */

	virtual void InitAbilityActorInfo() override;

public:
	/**
	 * Functions
	 */

	/* Combat Interface */
	virtual int32 GetPlayerLevel() override;
};
