// Fill out your copyright notice in the Description page of Project Settings.


#include "HintUserWidget.h"
#include "NursingLevelScript.h"

void UHintUserWidget::NativeConstruct() {
    Super::NativeConstruct();
}

void UHintUserWidget::UpdateHint(FString UpdatedHint)
{
    HintTextBox->SetText(FText::FromString(UpdatedHint));
}

void UHintUserWidget::UpdateTitle(FString UpdatedTitle)
{
    Title->SetText(FText::FromString(UpdatedTitle));
}