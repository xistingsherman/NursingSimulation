// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "MainMenuLevelScript.generated.h"

/**
 * 
 */
UCLASS()
class NURSINGSIMULATION_API AMainMenuLevelScript : public ALevelScriptActor
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

protected:

	UFUNCTION()
	void SelectDerrickLevel();

	UFUNCTION()
	void SelectPatriceLevel();

	UFUNCTION()
	void SelectHannahLevel();

	UFUNCTION()
	void SelectWesleyLevel();
};
