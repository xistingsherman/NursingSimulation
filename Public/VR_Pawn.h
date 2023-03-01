// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "HandControllerBase.h"
#include "VR_Pawn.generated.h"

UCLASS()
class NURSINGSIMULATION_API AVR_Pawn : public APawn
{
	GENERATED_BODY()

public:
	AVR_Pawn();

private:
	void RightTriggerPressed() { if (RightHandControllerBase) RightHandControllerBase->TriggerPressed(); }
	void RightTriggerReleased() { if (RightHandControllerBase) RightHandControllerBase->TriggerReleased(); }

	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent * PlayerInputComponent) override;

private:
	//Config
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AHandControllerBase> HandControllerBaseClass;

	//Components
	UPROPERTY(VisibleAnywhere)
	USceneComponent * VRRoot;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent * Camera;

	//References
	UPROPERTY()
	AHandControllerBase * RightHandControllerBase;

};
