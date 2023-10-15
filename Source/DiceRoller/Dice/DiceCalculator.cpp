//This Include
#include "../Dice/DiceCalculator.h"

//Engine Incluedes
#include "Engine/AssetManager.h"
#include "Kismet/KismetSystemLibrary.h"

//Local Includes
#include "Dice.h"



UDiceCalculator::UDiceCalculator(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}


int32 UDiceCalculator::RollAllStoredDice(bool bClearStoredResults, bool bClearStoredDice)
{
	if (bClearStoredResults)
	{
		ClearAllStoredDiceRollResults();
	}

	int32 Sum = 0;
	for (auto& DicePairing : StoredDiceToRoll)
	{
		//Roll Dices X times and add that to the sum and store each roll seperately in the case we need them
		UDice* RolledDice = DicePairing.Key;
		TArray<int32> RollsFromDice;
		for(int32 i = 0; i < DicePairing.Value; i++)
		{
			int32 DiceRoll = RolledDice->RollDice();
			Sum += DiceRoll;
			RollsFromDice.Add(DiceRoll);
		}

		FStoredDiceResult Results;
		Results.Dice = RolledDice;
		Results.StoredDiceRollResults = RollsFromDice;

		StoredDiceRollResults.Add(Results);
	}

	if (bClearStoredDice)
	{
		ClearAllStoredDice();
	}

	return Sum;
}

void UDiceCalculator::ClearAllStoredDice()
{
	StoredDiceToRoll.Empty();
}

bool UDiceCalculator::AddDice(UDice* AddedDice, int32 AmountToAdd) 
{
	if (AmountToAdd <= 0)
	{
		return false;
	}

	StoredDiceToRoll.Add(AddedDice,AmountToAdd);

	return true;
}

void UDiceCalculator::ClearAllStoredDiceRollResults()
{
	StoredDiceRollResults.Empty();
}

TArray<FStoredDiceResult> UDiceCalculator::GetAllStoredDiceRollResults()
{
	return StoredDiceRollResults;
}

TArray<TSoftClassPtr<UObject>> UDiceCalculator::GetDiceSoftClassReferences()
{
	if (DiceSoftClassReferences.Num() == 0)
	{
		TArray<FPrimaryAssetId> AssetData;
		const UAssetManager& AssetManager = UAssetManager::Get();
		const FName AssetType = UDice::StaticClass()->GetFName();
		AssetManager.GetPrimaryAssetIdList(FPrimaryAssetType(AssetType), AssetData);

		for (const FPrimaryAssetId& Asset : AssetData)
		{
			DiceSoftClassReferences.Add(UKismetSystemLibrary::GetSoftClassReferenceFromPrimaryAssetId(Asset));
		}
	}

	return DiceSoftClassReferences;
}
