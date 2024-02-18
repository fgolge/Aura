// Copyright M. Fatih Golge

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/PlayerInterface.h"
#include "AuraCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UNiagaraComponent;

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase, public IPlayerInterface
{
	GENERATED_BODY()

public:
	AAuraCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	/**
	 * Variables
	 */

	/* Components */

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> CameraBoom;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> TopDownCameraComponent;

	/**
	 * Functions
	 */

	/* Combat */

	UFUNCTION(NetMulticast, Reliable)
	void MulticastLevelUpParticles() const;
	
protected:
	/**
	 * Functions
	 */

	virtual void InitAbilityActorInfo() override;

public:
	/**
	 * Variables
	 */

	/* Combat */

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UNiagaraComponent> LevelUpNiagaraComponent;
	
	/**
	 * Functions
	 */

	/* Combat Interface */
	virtual int32 GetPlayerLevel_Implementation() override;
	
	/* Player Interface */
	virtual void AddToXP_Implementation(int32 InXP) override;
	virtual int32 GetXP_Implementation() const override;
	virtual int32 FindLevelForXP_Implementation(int32 InXP) const override;
	virtual void LevelUp_Implementation() override;
	virtual void AddToPlayerLevel_Implementation(int32 InPlayerLevel) const override;
	virtual int32 GetAttributePointsReward_Implementation(int32 Level) const override;
	virtual void AddToAttributePoints_Implementation(int32 InAttributePoints) const override;
	virtual int32 GetSpellPointsReward_Implementation(int32 Level) const override;
	virtual void AddToSpellPoints_Implementation(int32 InSpellPoints) const override;
};
