// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MotionControllerComponent.h"
#include "HandControllerBase.generated.h"


UCLASS()
class NURSINGSIMULATION_API AHandControllerBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AHandControllerBase();
	virtual void TriggerPressed();
	virtual void TriggerReleased();

private:
	//Components
	UPROPERTY(VisibleAnywhere)
	UMotionControllerComponent * MotionController;
};
