// Copyright M. Fatih Golge


#include "Input/AuraInputConfig.h"
#include "InputAction.h"

const UInputAction* UAuraInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag,
                                                                   bool bLogNotFound) const
{
	for(const FAuraInputAction& Action : AbilityInputActions)
	{
		if(Action.InputAction && Action.InputTag.MatchesTagExact(InputTag))
		{
			return Action.InputAction;
		}
	}

	if(bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find Ability Input Action for Input Tag [%s] on Input Config [%s]."), *InputTag.ToString(), *GetNameSafe(this));
	}

	return nullptr;
}
