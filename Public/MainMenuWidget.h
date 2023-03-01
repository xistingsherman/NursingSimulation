// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CheckBox.h"
#include "Components/Button.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class NURSINGSIMULATION_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

	protected:
		// Doing setup in the C++ constructor is not as
		// useful as using NativeConstruct.
		virtual void NativeConstruct() override;

		//man
		UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
		UCheckBox * ManCheckBox;

		//woman
		UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
		UCheckBox * WomanCheckBox;

		//black
		UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
		UCheckBox * BlackCheckBox;

		//white
		UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
		UCheckBox * WhiteCheckBox;

		//start simulation
		UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (BindWidget))
		UButton * BeginButton;

	private:
		UFUNCTION()
		void ManCheckBoxChanged(bool bIsChecked);
		
		UFUNCTION()
		void WomanCheckBoxChanged(bool bIsChecked);
		
		UFUNCTION()
		void BlackCheckBoxChanged(bool bIsChecked);
		
		UFUNCTION()
		void WhiteCheckBoxChanged(bool bIsChecked);

		UFUNCTION()
		void BeginButtonClicked();

		UPROPERTY(EditAnywhere)
		FName DerrickLevel = "Clinic_hospital_room_Derrick";

		UPROPERTY(EditAnywhere)
		FName HannahLevel = "Clinic_hospital_room_Hannah";

		UPROPERTY(EditAnywhere)
		FName WesleyLevel = "Clinic_hospital_room_Wesley";

		UPROPERTY(EditAnywhere)
		FName PatriceLevel = "Clinic_hospital_room_Patrice";
};
