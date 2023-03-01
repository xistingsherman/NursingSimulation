// Fill out your copyright notice in the Description page of Project Settings.

#include "VR_Pawn.h"

#include "Engine/World.h"

AVR_Pawn::AVR_Pawn()
{
	PrimaryActorTick.bCanEverTick = true;

	VRRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VRRoot"));
	SetRootComponent(VRRoot);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera -> SetupAttachment(VRRoot);

}

void AVR_Pawn::BeginPlay()
{
	Super::BeginPlay();

	RightHandControllerBase = nullptr;

	if (HandControllerBaseClass) {
		RightHandControllerBase = GetWorld() -> SpawnActor<AHandControllerBase>(HandControllerBaseClass);
		RightHandControllerBase -> AttachToComponent(GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
		RightHandControllerBase -> SetOwner(this);
	}
}

void AVR_Pawn::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent){
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("RightTrigger"), EInputEvent::IE_Pressed, this, &AVR_Pawn::RightTriggerPressed);
	PlayerInputComponent->BindAction(TEXT("RightTrigger"), EInputEvent::IE_Released, this, &AVR_Pawn::RightTriggerReleased);
}




