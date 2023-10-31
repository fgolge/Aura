// Copyright M. Fatih Golge

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	/**
	 * Variables
	 */

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

	/**
	 * Functions
	 */
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

protected:
	/**
	 * Functions
	 */

	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
