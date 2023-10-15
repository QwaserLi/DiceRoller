#pragma once

#include "Dice.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable, BlueprintType)
class DICEROLLER_API UDice : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, BlueprintNativeEvent)
	int32 RollDice();
protected:

private:

public:

protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Dice")
	int32 MaxDiceNumber = 6;
private:

};
