// Fill out your copyright notice in the Description page of Project Settings.


#include "HandControllerBase.h"

AHandControllerBase::AHandControllerBase()
{
	PrimaryActorTick.bCanEverTick = false;

	MotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionController"));
	SetRootComponent(MotionController);

	MotionController->SetTrackingSource(EControllerHand::Right);
	MotionController->SetShowDeviceModel(true);
}


void AHandControllerBase::TriggerPressed() {

}

void AHandControllerBase::TriggerReleased() {

}
