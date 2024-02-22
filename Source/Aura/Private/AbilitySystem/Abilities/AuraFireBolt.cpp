// Copyright M. Fatih Golge


#include "AbilitySystem/Abilities/AuraFireBolt.h"

FString UAuraFireBolt::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);

	if (Level == 1)
	{
		return FString::Printf(
			TEXT(
				// Title
				"<TITLE>FIRE BOLT</>\n\n"

				// Level
				"<Small>Level: </><Level>%d</>\n"

				// ManaCost
				"<Small>Mana Cost: </><ManaCost>%.1f</>\n"

				// Cooldown
				"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

				"<Default>Launches a bolt of fire, exploding on impact and dealing </>"

				// Damage
				"<Damage>%d</>"

				"<Default> fire damage with a chance to burn</>"),

			// Parameters
			Level,
			ManaCost,
			Cooldown,
			ScaledDamage);
	}
	else
	{
		return FString::Printf(
			TEXT(
				// Title
				"<TITLE>FIRE BOLT</>\n\n"

				// Level
				"<Small>Level: </><Level>%d</>\n"

				// ManaCost
				"<Small>Mana Cost: </><ManaCost>%.1f</>\n"

				// Cooldown
				"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

				"<Default>Launches %d bolt of fire, exploding on impact and dealing </>"

				// Damage
				"<Damage>%d</>"

				"<Default> fire damage with a chance to burn</>"),

			// Parameters
			Level,
			ManaCost,
			Cooldown,
			FMath::Min(Level, NumProjectiles),
			ScaledDamage);
	}
}

FString UAuraFireBolt::GetNextLevelDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);

	return FString::Printf(
		TEXT(
			// Title
			"<TITLE>NEXT LEVEL</>\n\n"

			// Level
			"<Small>Level: </><Level>%d</>\n"

			// ManaCost
			"<Small>Mana Cost: </><ManaCost>%.1f</>\n"

			// Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

			"<Default>Launches %d bolt of fire, exploding on impact and dealing </>"

			// Damage
			"<Damage>%d</>"

			"<Default> fire damage with a chance to burn</>"),

		// Parameters
		Level,
		ManaCost,
		Cooldown,
		FMath::Min(Level, NumProjectiles),
		ScaledDamage);
}
