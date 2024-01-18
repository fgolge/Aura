// Copyright M. Fatih Golge


#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	check(AttributeInfo);

	for (auto Info : AttributeInfo.Get()->AttributeInformation)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Info.AttributeGetter).AddLambda(
			[this, Info] (const FOnAttributeChangeData& Data)
			{
				BroadcastAttributeInfo(Info);
			});
	}
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	check(AttributeInfo);

	for (auto Info : AttributeInfo.Get()->AttributeInformation)
	{
		BroadcastAttributeInfo(Info);
	}
}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FAuraAttributeInfo& Info) const
{
	FAuraAttributeInfo NewInfo = AttributeInfo->FindAttributeInfoForTag(Info.AttributeTag);
	NewInfo.AttributeValue = Info.AttributeGetter.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(NewInfo);
}
