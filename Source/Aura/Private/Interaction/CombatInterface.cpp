// Copyright M. Fatih Golge


#include "Interaction/CombatInterface.h"

// Add default functionality here for any ICombatInterface functions that are not pure virtual.

// Since we don't want it to be necessarily implemented, we define it in the interface
int32 ICombatInterface::GetPlayerLevel()
{
	return 0;
}
