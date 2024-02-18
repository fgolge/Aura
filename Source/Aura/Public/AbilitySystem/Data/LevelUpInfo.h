// Copyright M. Fatih Golge

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LevelUpInfo.generated.h"

USTRUCT(BlueprintType)
struct FAuraLevelUpInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 LevelUpRequirement{0};

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 AttributePointReward{0};

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 SpellPointReward{0};
};

/**
 * 
 */
UCLASS()
class AURA_API ULevelUpInfo : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "LevelUpInformation")
	TArray<FAuraLevelUpInfo> LevelUpInformation;

	int32 FindLevelForXP(int32 XP) const;
};
