// Copyright M. Fatih Golge

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AuraAbilitySystemComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTags, const FGameplayTagContainer& /* Asset Tags */);

/**
 * 
 */
UCLASS()
class AURA_API UAuraAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

protected:
	/**
	 * Functions
	 */

	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec,
	                   FActiveGameplayEffectHandle EffectHandle);

public:
	/**
	 * Variables
	 */

	FEffectAssetTags EffectAssetTags;
	
	/**
	 * Functions
	 */

	void AbilityActorInfoSet();
};
