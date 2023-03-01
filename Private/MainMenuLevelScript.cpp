// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuLevelScript.h"
#include "Kismet/StereoLayerFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

void AMainMenuLevelScript::BeginPlay(){

    Super::BeginPlay();

    InputComponent->BindAction("SelectDerrickLevel", IE_Pressed, this, &AMainMenuLevelScript::SelectDerrickLevel);
    InputComponent->BindAction("SelectPatriceLevel", IE_Released, this, &AMainMenuLevelScript::SelectPatriceLevel);
    InputComponent->BindAction("SelectHannahLevel", IE_Pressed, this, &AMainMenuLevelScript::SelectHannahLevel);
    InputComponent->BindAction("SelectWesleyLevel", IE_Released, this, &AMainMenuLevelScript::SelectWesleyLevel);
}


void AMainMenuLevelScript::SelectDerrickLevel() {
    UE_LOG(LogTemp, Warning, TEXT("This is working... partially."));
    UGameplayStatics::OpenLevel(GetWorld(), "Clinic_hospital_room_Derrick", true);
}

void AMainMenuLevelScript::SelectPatriceLevel() {
    UStereoLayerFunctionLibrary::ShowSplashScreen();
    UGameplayStatics::OpenLevel(GetWorld(), "Clinic_hospital_room_Derrick", true);
}

void AMainMenuLevelScript::SelectHannahLevel() {
    UStereoLayerFunctionLibrary::ShowSplashScreen();
    UGameplayStatics::OpenLevel(GetWorld(), "Clinic_hospital_room_Hannah", true);
}

void AMainMenuLevelScript::SelectWesleyLevel() {
    UStereoLayerFunctionLibrary::ShowSplashScreen();
    UGameplayStatics::OpenLevel(GetWorld(), "Clinic_hospital_room_Wesley", true);
}