// Copyright M. Fatih Golge

#pragma once

#include "GameplayEffectTypes.h"
#include "AuraAbilityTypes.generated.h"

class UGameplayEffect;

USTRUCT(BlueprintType)
struct FDamageEffectParams
{
	GENERATED_BODY()

	FDamageEffectParams()
	{
	}

	UPROPERTY()
	TObjectPtr<UObject> WorldContextObject{nullptr};

	UPROPERTY()
	TSubclassOf<UGameplayEffect> DamageGameplayEffectClass{nullptr};

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> SourceAbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> TargetAbilitySystemComponent;

	UPROPERTY()
	float BaseDamage{0.f};

	UPROPERTY()
	float AbilityLevel{0.f};

	UPROPERTY()
	FGameplayTag DamageType{FGameplayTag()};

	UPROPERTY()
	float DebuffChance{0.f};

	UPROPERTY()
	float DebuffDamage{0.f};

	UPROPERTY()
	float DebuffDuration{0.f};

	UPROPERTY()
	float DebuffFrequency{0.f};

	UPROPERTY()
	float DeathImpulseMagnitude{0.f};

	UPROPERTY()
	FVector DeathImpulse{FVector::ZeroVector};
};

USTRUCT(BlueprintType)
struct FAuraGameplayEffectContext : public FGameplayEffectContext
{
	GENERATED_BODY()

public:
	bool IsBlockedHit() const { return bIsBlockedHit; }
	bool IsCriticalHit() const { return bIsCriticalHit; }
	bool IsSuccessfulDebuff() const { return bIsSuccessfulDebuff; }
	float GetDebuffDamage() const { return DebuffDamage; }
	float GetDebuffDuration() const { return DebuffDuration; }
	float GetDebuffFrequency() const { return DebuffFrequency; }
	TSharedPtr<FGameplayTag> GetDamageType() const { return DamageType; }
	FVector GetDeathImpulse() const { return DeathImpulse; }

	void SetIsBlockedHit(const bool bInIsBlockedHit) { bIsBlockedHit = bInIsBlockedHit; }
	void SetIsCriticalHit(const bool bInIsCriticalHit) { bIsCriticalHit = bInIsCriticalHit; }
	void SetIsSuccessfulDebuff(const bool bInIsSuccessfulDebuff) { bIsSuccessfulDebuff = bInIsSuccessfulDebuff; }
	void SetDebuffDamage(const float InDebuffDamage) { DebuffDamage = InDebuffDamage; }
	void SetDebuffDuration(const float InDebuffDuration) { DebuffDuration = InDebuffDuration; }
	void SetDebuffFrequency(const float InDebuffFrequency) { DebuffFrequency = InDebuffFrequency; }
	void SetDamageType(const TSharedPtr<FGameplayTag>& InDamageType) { DamageType = InDamageType; }
	void SetDeathImpulse(const FVector InDeathImpulse) { DeathImpulse = InDeathImpulse; }


	// Returns the actual struct used for serialization.
	virtual UScriptStruct* GetScriptStruct() const
	{
		return FGameplayEffectContext::StaticStruct();
	}

	// Creates a copy of this context, used to duplicate for later modifications */
	virtual FGameplayEffectContext* Duplicate() const
	{
		FGameplayEffectContext* NewContext = new FGameplayEffectContext();
		*NewContext = *this;
		if (GetHitResult())
		{
			// Does a deep copy of the hit result
			NewContext->AddHitResult(*GetHitResult(), true);
		}
		return NewContext;
	}

	// Custom serialization
	virtual bool NetSerialize(FArchive& Ar, UPackageMap* Map, bool& bOutSuccess) override;

protected:
	UPROPERTY()
	bool bIsBlockedHit{false};

	UPROPERTY()
	bool bIsCriticalHit{false};

	UPROPERTY()
	bool bIsSuccessfulDebuff{false};

	UPROPERTY()
	float DebuffDamage{0.f};

	UPROPERTY()
	float DebuffDuration{0.f};

	UPROPERTY()
	float DebuffFrequency{0.f};

	TSharedPtr<FGameplayTag> DamageType;

	UPROPERTY()
	FVector DeathImpulse{FVector::ZeroVector};
};

template <>
struct TStructOpsTypeTraits<FAuraGameplayEffectContext> : public TStructOpsTypeTraitsBase2<FAuraGameplayEffectContext>
{
	enum
	{
		WithNetSerializer = true,
		WithCopy = true
	};
};
