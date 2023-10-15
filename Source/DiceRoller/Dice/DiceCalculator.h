#pragma once

//Engine Includes
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

//Local Includes
#include "../Dice/Dice.h"

//Generated Includes
#include "DiceCalculator.generated.h"

//Forward Declares
class UDice;

USTRUCT(BlueprintType)
struct FStoredDiceResult {
	GENERATED_BODY()

	UDice* Dice;
	TArray<int32> StoredDiceRollResults;
};

/**
 * 
 */
UCLASS(BlueprintType)
class DICEROLLER_API UDiceCalculator : public UObject
{
	GENERATED_BODY()
	
public:
	UDiceCalculator(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable)
	bool AddDice(UDice* AddedDice, int32 AmountToAdd = 1);

	UFUNCTION(BlueprintCallable)
	int32 RollAllStoredDice(bool bClearStoredResults, bool bClearStoredDice);

	UFUNCTION(BlueprintCallable)
	void ClearAllStoredDice();

	UFUNCTION(BlueprintCallable)
	void ClearAllStoredDiceRollResults();

	UFUNCTION(BlueprintPure)
	TArray<FStoredDiceResult> GetAllStoredDiceRollResults();

	UFUNCTION(BlueprintPure)
	TArray<TSoftClassPtr<UObject>> GetDiceSoftClassReferences();

protected:

private:

public:

protected:
	TMap<UDice*, int32> StoredDiceToRoll;

	TArray<FStoredDiceResult> StoredDiceRollResults;

	TArray<TSoftClassPtr<UObject>> DiceSoftClassReferences;

private:

	
};
