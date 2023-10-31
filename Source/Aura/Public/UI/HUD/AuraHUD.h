// Copyright M. Fatih Golge

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UAuraUserWidget;
/**
 * 
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()

protected:
virtual void BeginPlay() override;
	
public:
	/**
	 * Variables
	 */
	
	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget;

private:
	/**
	 * Variables
	 */
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;
};
