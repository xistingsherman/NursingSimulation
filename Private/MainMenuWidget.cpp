// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenuWidget.h"
#include "Kismet/StereoLayerFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuWidget::NativeConstruct(){
    Super::NativeConstruct();

    BeginButton->OnClicked.AddDynamic(this, &UMainMenuWidget::BeginButtonClicked);

    ManCheckBox->OnCheckStateChanged.AddDynamic(this, &UMainMenuWidget::ManCheckBoxChanged);
    WomanCheckBox->OnCheckStateChanged.AddDynamic(this, &UMainMenuWidget::WomanCheckBoxChanged);
    BlackCheckBox->OnCheckStateChanged.AddDynamic(this, &UMainMenuWidget::BlackCheckBoxChanged);
    WhiteCheckBox->OnCheckStateChanged.AddDynamic(this, &UMainMenuWidget::WhiteCheckBoxChanged);

    UE_LOG(LogTemp, Warning, TEXT("Set Up is Working"));
}

void UMainMenuWidget::ManCheckBoxChanged(bool bIsChecked) {
    UE_LOG(LogTemp, Warning, TEXT("This is working (Man)"));
    //if man is selected, woman is deselected
    if (bIsChecked) {
        WomanCheckBox->SetCheckedState(ECheckBoxState::Unchecked);
        UE_LOG(LogTemp, Warning, TEXT("Woman Box Checked"));

        if ((BlackCheckBox->GetCheckedState() == ECheckBoxState::Checked) || (WhiteCheckBox->GetCheckedState() == ECheckBoxState::Checked)) {
            BeginButton->SetIsEnabled(true);
        }
        else {
            BeginButton->SetIsEnabled(false);
        }
    }

    
}

void UMainMenuWidget::WomanCheckBoxChanged(bool bIsChecked) {
    UE_LOG(LogTemp, Warning, TEXT("This is working (Woman)"));
    
    //if woman is selected, man is deselected
    if (bIsChecked) {
        ManCheckBox->SetCheckedState(ECheckBoxState::Unchecked);
        UE_LOG(LogTemp, Warning, TEXT("Man Box Checked"));

        if ((BlackCheckBox->GetCheckedState() == ECheckBoxState::Checked) || (WhiteCheckBox->GetCheckedState() == ECheckBoxState::Checked)) {
            BeginButton->SetIsEnabled(true);
        }
        else {
            BeginButton->SetIsEnabled(false);
        }
    }


}

void UMainMenuWidget::BlackCheckBoxChanged(bool bIsChecked) {

    //if Black is selected, white is deselected
    if (bIsChecked) {
        WhiteCheckBox->SetCheckedState(ECheckBoxState::Unchecked);
        UE_LOG(LogTemp, Warning, TEXT("Black Box Checked"));

        if ((WomanCheckBox->GetCheckedState() == ECheckBoxState::Checked) || (ManCheckBox->GetCheckedState() == ECheckBoxState::Checked)) {
            BeginButton->SetIsEnabled(true);
        }
        else {
            BeginButton->SetIsEnabled(false);
        }
    }
}

void UMainMenuWidget::WhiteCheckBoxChanged(bool bIsChecked) {

    //if white is selected, black is deselected
    if (bIsChecked) {
        BlackCheckBox->SetCheckedState(ECheckBoxState::Unchecked);
        UE_LOG(LogTemp, Warning, TEXT("White Box Checked"));

        if ((WomanCheckBox->GetCheckedState() == ECheckBoxState::Checked) || (ManCheckBox->GetCheckedState() == ECheckBoxState::Checked)) {
            BeginButton->SetIsEnabled(true);
        }
        else {
            BeginButton->SetIsEnabled(false);
        }
    }

}

void UMainMenuWidget::BeginButtonClicked(){

    UE_LOG(LogTemp, Warning, TEXT("Confirm Button is Working"));

    if(WomanCheckBox->GetCheckedState() == ECheckBoxState::Checked && BlackCheckBox->GetCheckedState() == ECheckBoxState::Checked) {
        UStereoLayerFunctionLibrary::ShowSplashScreen();
        UGameplayStatics::OpenLevel(GetWorld(), "Clinic_hospital_room_Patrice", true);
    }
    else if(WomanCheckBox->GetCheckedState() == ECheckBoxState::Checked && WhiteCheckBox->GetCheckedState() == ECheckBoxState::Checked){
        UStereoLayerFunctionLibrary::ShowSplashScreen();
        UGameplayStatics::OpenLevel(GetWorld(), "Clinic_hospital_room_Hannah", true);
    }
    else if(ManCheckBox->GetCheckedState() == ECheckBoxState::Checked && BlackCheckBox->GetCheckedState() == ECheckBoxState::Checked){
        UStereoLayerFunctionLibrary::ShowSplashScreen();
        UGameplayStatics::OpenLevel(GetWorld(), "Clinic_hospital_room_Derrick", true);
    }
    else if(ManCheckBox->GetCheckedState() == ECheckBoxState::Checked && WhiteCheckBox->GetCheckedState() == ECheckBoxState::Checked){
        UStereoLayerFunctionLibrary::ShowSplashScreen();
        UGameplayStatics::OpenLevel(GetWorld(), "Clinic_hospital_room_Wesley", true);
    }
}

