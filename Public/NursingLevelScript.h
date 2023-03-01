// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "LevelSequence.h"
#include "InputCoreTypes.h"
#include <LevelSequenceActor.h>
#include <LevelSequencePlayer.h>
#include <MovieSceneSequencePlayer.h>
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UnrealClient.h"
#include "Misc/FileHelper.h"
#include "Engine/DataTable.h"
#include "Kismet/GameplayStatics.h"
#include "HintUserWidget.h"

#include "NursingLevelScript.generated.h"


USTRUCT(BlueprintType)
struct FHintStructure : public FTableRowBase {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Hint = "DefaultName";

};

USTRUCT(BlueprintType)
struct FPatientScriptStructure : public FTableRowBase {
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString PatientScript = "DefaultName";

};
/**
 * 
 */
UCLASS()
class NURSINGSIMULATION_API ANursingLevelScript : public ALevelScriptActor
{
	GENERATED_BODY()

	public:
		virtual void BeginPlay() override;

	protected:
		void AddZero();
    	void SubtractZero();
		void AddOne();
    	void SubtractOne();
		void AddTwo();
    	void SubtractTwo();
		void AddThree();
    	void SubtractThree();
		void AddFour();
    	void SubtractFour();
		void AddFive();
    	void SubtractFive();
		void AddSix();
    	void SubtractSix();
		void AddSeven();
    	void SubtractSeven();
		void AddEight();
    	void SubtractEight();
		void AddNine();
    	void SubtractNine();

		void ToggleOnSingleDigit();
    	void ToggleOffSingleDigit();
		void ToggleOnTens();
    	void ToggleOffTens();
		void ToggleOnTwenties();
    	void ToggleOffTwenties();
		void ToggleOnThirties();
    	void ToggleOffThirties();
		void ToggleOnForties();
    	void ToggleOffForties();

		void PlaySequence();
		void PlayTimeVague();
		void PlayTimeFrequency();
		void PlayIDK();
		void PlayRepeatThat();
		void PlayYes();
		void PlayNo();
		void PlayMaybe();
		void PlayBreakfast();
		void PlayLunch();
		void PlayGreens();
		void ResetPosition();
		void ReturnToMainMenu();
		void AdjustHeight();
		void ShowNextHint();
		void DisplayScript();
		void EndSimulation();



	private:
		UPROPERTY(EditAnywhere)
		TArray<ULevelSequence*> LevelSequences;
		
		UPROPERTY(EditAnywhere)
		TArray<ULevelSequence*> TimeVagueSequences;
		
		UPROPERTY(EditAnywhere)
		TArray<ULevelSequence*> TimeFrequencySequences;

		UPROPERTY(EditAnywhere)
		TArray<ULevelSequence*> IDKSequences;

		UPROPERTY(EditAnywhere)
		TArray<ULevelSequence*> RepeatThatSequences;

		UPROPERTY(EditAnywhere)
		TArray<ULevelSequence*> YesSequences;

		UPROPERTY(EditAnywhere)
		TArray<ULevelSequence*> NoSequences;

		UPROPERTY(EditAnywhere)
		ULevelSequence * MaybeSequence;

		UPROPERTY(EditAnywhere)
		ULevelSequence* BreakfastSequence;

		UPROPERTY(EditAnywhere)
		ULevelSequence* LunchSequence;

		UPROPERTY(EditAnywhere)
		ULevelSequence* GreensSequence;

		UPROPERTY(EditAnywhere)
		UDataTable* HintTable;

		UPROPERTY(EditAnywhere)
		UDataTable* PatientScriptTable;

		UPROPERTY(VisibleAnywhere)
		bool SingleDigit;

		UPROPERTY(VisibleAnywhere)
		bool Tens;

		UPROPERTY(VisibleAnywhere)
		bool Twenties;

		UPROPERTY(VisibleAnywhere)
		bool Thirties;

		UPROPERTY(VisibleAnywhere)
		bool Forties;

		UPROPERTY(VisibleAnywhere)
		bool IsPlaying;

		UPROPERTY(VisibleAnywhere)
		int CurrentValue;

		FMovieSceneSequencePlaybackSettings PlaybackSettings;
		ALevelSequenceActor * OutActor;
		ULevelSequencePlayer* SequencePlayer;
		UHintUserWidget* HintUserWidgetEdit;
		FHintStructure* HintRow;
		FPatientScriptStructure* PatientScriptRow;
		FVector OriginalLocation;
		int RandomNum;
		int CurrentHintValue;
		
};
