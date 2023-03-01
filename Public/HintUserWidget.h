// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/MultiLineEditableTextBox.h"
#include "Components/TextBlock.h"
#include "HintUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class NURSINGSIMULATION_API UHintUserWidget : public UUserWidget
{
	GENERATED_BODY()
	

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UMultiLineEditableTextBox * HintTextBox;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
	UTextBlock * Title;

	virtual void NativeConstruct();

	UFUNCTION()
	void UpdateHint(FString UpdatedHint);

	void UpdateTitle(FString UpdatedTitle);

public:
	FString Hint;
};
