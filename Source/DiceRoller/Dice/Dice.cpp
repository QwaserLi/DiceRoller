//This include
#include "../Dice/Dice.h"

//Engine Incluedes

//Local Includes


int32 UDice::RollDice_Implementation()
{
	return FMath::RandRange(1, MaxDiceNumber);
}