// Fill out your copyright notice in the Description page of Project Settings.
#include "NursingLevelScript.h"
#include "EngineUtils.h"
#include "Containers/Array.h"
#include "Components/WidgetComponent.h"
#include "Components/ActorComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/StereoLayerFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

void ANursingLevelScript::AddZero()
{
    CurrentValue += 0;

    if (SingleDigit || Tens || Twenties || Thirties || Forties) {
        PlaySequence();
    }
    
    UE_LOG(LogTemp, Warning, TEXT("Pressed Num 0"));
}

void ANursingLevelScript::SubtractZero()
{
    CurrentValue -= 0;
    UE_LOG(LogTemp, Warning, TEXT("Released Num 0"));
}
void ANursingLevelScript::AddOne()
{
    CurrentValue += 1;
    PlaySequence();
    UE_LOG(LogTemp, Warning, TEXT("Pressed Num 1"));
}

void ANursingLevelScript::SubtractOne()
{
    CurrentValue -= 1;
    UE_LOG(LogTemp, Warning, TEXT("Released Num 1"));
}
void ANursingLevelScript::AddTwo()
{
    CurrentValue += 2;
    PlaySequence();
    UE_LOG(LogTemp, Warning, TEXT("Pressed Num 2"));
}

void ANursingLevelScript::SubtractTwo()
{
    CurrentValue -= 2;
    UE_LOG(LogTemp, Warning, TEXT("Released Num 2"));
}
void ANursingLevelScript::AddThree()
{
    CurrentValue += 3;
    PlaySequence();
    UE_LOG(LogTemp, Warning, TEXT("Pressed Num 3"));
}

void ANursingLevelScript::SubtractThree()
{
    CurrentValue -= 3;
    UE_LOG(LogTemp, Warning, TEXT("Released Num 3"));
}
void ANursingLevelScript::AddFour()
{
    CurrentValue += 4;
    PlaySequence();
    UE_LOG(LogTemp, Warning, TEXT("Pressed Num 4"));
}

void ANursingLevelScript::SubtractFour()
{
    CurrentValue -= 4;
    UE_LOG(LogTemp, Warning, TEXT("Released Num 4"));
}
void ANursingLevelScript::AddFive()
{
    CurrentValue += 5;
    PlaySequence();
    UE_LOG(LogTemp, Warning, TEXT("Pressed Num 5"));
}

void ANursingLevelScript::SubtractFive()
{
    CurrentValue -= 5;
    UE_LOG(LogTemp, Warning, TEXT("Released Num 5"));
}
void ANursingLevelScript::AddSix()
{
    CurrentValue += 6;
    PlaySequence();
    UE_LOG(LogTemp, Warning, TEXT("Pressed Num 6"));
}

void ANursingLevelScript::SubtractSix()
{
    CurrentValue -= 6;
    UE_LOG(LogTemp, Warning, TEXT("Released Num 6"));
}
void ANursingLevelScript::AddSeven()
{
    CurrentValue += 7;
    PlaySequence();
    UE_LOG(LogTemp, Warning, TEXT("Pressed Num 7"));
}

void ANursingLevelScript::SubtractSeven()
{
    CurrentValue -= 7;
    UE_LOG(LogTemp, Warning, TEXT("Released Num 7"));
}
void ANursingLevelScript::AddEight()
{
    CurrentValue += 8;
    PlaySequence();
    UE_LOG(LogTemp, Warning, TEXT("Pressed Num 8"));
}

void ANursingLevelScript::SubtractEight()
{
    CurrentValue -= 8;
    UE_LOG(LogTemp, Warning, TEXT("Released Num 8"));
}
void ANursingLevelScript::AddNine()
{
    CurrentValue += 9;
    PlaySequence();
    UE_LOG(LogTemp, Warning, TEXT("Pressed Num 9"));
}

void ANursingLevelScript::SubtractNine()
{
    CurrentValue -= 9;
    UE_LOG(LogTemp, Warning, TEXT("Released Num 9"));
}

void ANursingLevelScript::ToggleOnTens()
{
    CurrentValue += 10;
    UE_LOG(LogTemp, Warning, TEXT("Pressed Num /"));
}

void ANursingLevelScript::ToggleOffTens()
{
    CurrentValue -= 10;
    UE_LOG(LogTemp, Warning, TEXT("Released Num /"));
}

void ANursingLevelScript::ToggleOnTwenties()
{
    CurrentValue += 20;
    UE_LOG(LogTemp, Warning, TEXT("Pressed Num *"));
}

void ANursingLevelScript::ToggleOffTwenties()
{
    CurrentValue -= 20;
    UE_LOG(LogTemp, Warning, TEXT("Released Num *"));
}

void ANursingLevelScript::ToggleOnThirties()
{
    CurrentValue += 30;
    UE_LOG(LogTemp, Warning, TEXT("Pressed Num -"));
}

void ANursingLevelScript::ToggleOffThirties()
{
    CurrentValue -= 30;
    UE_LOG(LogTemp, Warning, TEXT("Released Num -"));
}

void ANursingLevelScript::ToggleOnForties()
{
    CurrentValue += 40;
    UE_LOG(LogTemp, Warning, TEXT("Pressed Num +"));
}

void ANursingLevelScript::ToggleOffForties()
{
    CurrentValue -= 40;
    UE_LOG(LogTemp, Warning, TEXT("Released Num +"));
}

void ANursingLevelScript::ToggleOnSingleDigit()
{
    UE_LOG(LogTemp, Warning, TEXT("Pressed Num ."));
}

void ANursingLevelScript::ToggleOffSingleDigit()
{
    UE_LOG(LogTemp, Warning, TEXT("Released Num ."));
}


// Called when the game starts or when spawned
void ANursingLevelScript::BeginPlay()
{
    Super::BeginPlay();
  
    CurrentValue = 0;
    CurrentHintValue = 0;
    //OriginalLocation = 

    SingleDigit = false;
    Tens = false;
    Twenties = false;
    Thirties = false;
    Forties = false;

    PlaybackSettings = FMovieSceneSequencePlaybackSettings();

    TArray<AActor*> OutActors;
    AActor * HintUI = nullptr;

    UGameplayStatics::GetAllActorsOfClass(this, AActor::StaticClass(), OutActors);

    if (!OutActors.IsEmpty()) {
        for (AActor* SomeActor : OutActors) {
            if (SomeActor->GetName().Contains("BP_HintsUI")) {
                HintUI = SomeActor;
                UE_LOG(LogTemp, Warning, TEXT("This is the BP UI: %s"), *HintUI->GetName());
            }
        }

        if (HintUI) {
            HintUserWidgetEdit = nullptr;
            TSet<UActorComponent*> HintComponents = HintUI->GetComponents();

            if (!HintComponents.IsEmpty()) {
                for (UActorComponent* SomeComponent : HintComponents) {
                    if (SomeComponent->GetName().Contains("HintUserWidget")) {
                        HintUserWidgetEdit = Cast<UHintUserWidget>(Cast<UWidgetComponent>(SomeComponent)->GetUserWidgetObject());
                        UE_LOG(LogTemp, Warning, TEXT("This is the WidgetComponent: %s"), *HintUserWidgetEdit->GetName());
                    }
                }                
            }
        }
        
    }
    HintRow = nullptr;

    /*
    if (HintTable && HintUserWidgetEdit) {
        HintRow = HintTable->FindRow<FHintStructure>(* FString::FromInt(CurrentHintValue), "");
        if (HintRow) {
            HintUserWidgetEdit->UpdateHint(FString(HintRow->Hint));
            UE_LOG(LogTemp, Warning, TEXT("This is the hint: %s"), *FString(HintRow->Hint));
        }
    }
    */

    //if program crashes unexpectedly, delete this section, recompile, then add section again and recompile.
    InputComponent->BindAction("PlayZero", IE_Pressed, this, &ANursingLevelScript::AddZero);
    InputComponent->BindAction("PlayZero", IE_Released, this, &ANursingLevelScript::SubtractZero);
    InputComponent->BindAction("PlayOne", IE_Pressed, this, &ANursingLevelScript::AddOne);
    InputComponent->BindAction("PlayOne", IE_Released, this, &ANursingLevelScript::SubtractOne);
    InputComponent->BindAction("PlayTwo", IE_Pressed, this, &ANursingLevelScript::AddTwo);
    InputComponent->BindAction("PlayTwo", IE_Released, this, &ANursingLevelScript::SubtractTwo);
    InputComponent->BindAction("PlayThree", IE_Pressed, this, &ANursingLevelScript::AddThree);
    InputComponent->BindAction("PlayThree", IE_Released, this, &ANursingLevelScript::SubtractThree);
    InputComponent->BindAction("PlayFour", IE_Pressed, this, &ANursingLevelScript::AddFour);
    InputComponent->BindAction("PlayFour", IE_Released, this, &ANursingLevelScript::SubtractFour);
    InputComponent->BindAction("PlayFive", IE_Pressed, this, &ANursingLevelScript::AddFive);
    InputComponent->BindAction("PlayFive", IE_Released, this, &ANursingLevelScript::SubtractFive);
    InputComponent->BindAction("PlaySix", IE_Pressed, this, &ANursingLevelScript::AddSix);
    InputComponent->BindAction("PlaySix", IE_Released, this, &ANursingLevelScript::SubtractSix);
    InputComponent->BindAction("PlaySeven", IE_Pressed, this, &ANursingLevelScript::AddSeven);
    InputComponent->BindAction("PlaySeven", IE_Released, this, &ANursingLevelScript::SubtractSeven);
    InputComponent->BindAction("PlayEight", IE_Pressed, this, &ANursingLevelScript::AddEight);
    InputComponent->BindAction("PlayEight", IE_Released, this, &ANursingLevelScript::SubtractEight);
    InputComponent->BindAction("PlayNine", IE_Pressed, this, &ANursingLevelScript::AddNine);
    InputComponent->BindAction("PlayNine", IE_Released, this, &ANursingLevelScript::SubtractNine);


    InputComponent->BindAction("PlaySingleDigit", IE_Pressed, this, &ANursingLevelScript::ToggleOnSingleDigit);
    InputComponent->BindAction("PlaySingleDigit", IE_Released, this, &ANursingLevelScript::ToggleOffSingleDigit);
    InputComponent->BindAction("PlayTen", IE_Pressed, this, &ANursingLevelScript::ToggleOnTens);
    InputComponent->BindAction("PlayTen", IE_Released, this, &ANursingLevelScript::ToggleOffTens);
    InputComponent->BindAction("PlayTwenty", IE_Pressed, this, &ANursingLevelScript::ToggleOnTwenties);
    InputComponent->BindAction("PlayTwenty", IE_Released, this, &ANursingLevelScript::ToggleOffTwenties);
    InputComponent->BindAction("PlayThirty", IE_Pressed, this, &ANursingLevelScript::ToggleOnThirties);
    InputComponent->BindAction("PlayThirty", IE_Released, this, &ANursingLevelScript::ToggleOffThirties);
    InputComponent->BindAction("PlayForty", IE_Pressed, this, &ANursingLevelScript::ToggleOnForties);
    InputComponent->BindAction("PlayForty", IE_Released, this, &ANursingLevelScript::ToggleOffForties);

    InputComponent->BindAction("TimeVague", IE_Pressed, this, &ANursingLevelScript::PlayTimeVague);
    InputComponent->BindAction("TimeFrequency", IE_Pressed, this, &ANursingLevelScript::PlayTimeFrequency);
    InputComponent->BindAction("DontKnow", IE_Pressed, this, &ANursingLevelScript::PlayIDK);
    InputComponent->BindAction("RepeatThat", IE_Pressed, this, &ANursingLevelScript::PlayRepeatThat);
    InputComponent->BindAction("Yes", IE_Pressed, this, &ANursingLevelScript::PlayYes);
    InputComponent->BindAction("No", IE_Pressed, this, &ANursingLevelScript::PlayNo);
    InputComponent->BindAction("Maybe", IE_Pressed, this, &ANursingLevelScript::PlayMaybe);
    InputComponent->BindAction("Breakfast", IE_Pressed, this, &ANursingLevelScript::PlayBreakfast);
    InputComponent->BindAction("Lunch", IE_Pressed, this, &ANursingLevelScript::PlayLunch);
    InputComponent->BindAction("Greens", IE_Pressed, this, &ANursingLevelScript::PlayGreens);


    //TODO add Reset Position functionality
    InputComponent->BindAction("ResetPosition", IE_Pressed, this, &ANursingLevelScript::ResetPosition);
    //TODO add return to Main Menu functionality?
    
    //TODO add adjust heigh functionality
    InputComponent->BindAction("Height", IE_Pressed, this, &ANursingLevelScript::AdjustHeight);

    InputComponent->BindAction("NextHint", IE_Pressed, this, &ANursingLevelScript::ShowNextHint);
    InputComponent->BindAction("ReturnToMainMenu", IE_Pressed, this, &ANursingLevelScript::ReturnToMainMenu);
    InputComponent->BindAction("EndSimulation", IE_Pressed, this, &ANursingLevelScript::EndSimulation);
}


void ANursingLevelScript::PlayTimeVague() {
    if (!TimeVagueSequences.IsEmpty()) {
        RandomNum = FMath::RandRange(0, TimeVagueSequences.Max() - 1);
        SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), TimeVagueSequences[RandomNum], PlaybackSettings, OutActor);
        SequencePlayer->Play();
    }
}
void ANursingLevelScript::PlayTimeFrequency() {
    if (!TimeFrequencySequences.IsEmpty()) {
        RandomNum = FMath::RandRange(0, TimeFrequencySequences.Max() - 1);
        SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), TimeFrequencySequences[RandomNum], PlaybackSettings, OutActor);
        SequencePlayer->Play();
    }
}
void ANursingLevelScript::PlayIDK() {
    if (!IDKSequences.IsEmpty()) {
        RandomNum = FMath::RandRange(0, IDKSequences.Max() - 1);
        SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), IDKSequences[RandomNum], PlaybackSettings, OutActor);
        SequencePlayer->Play();
    }
}
void ANursingLevelScript::PlayRepeatThat() {
    if (!RepeatThatSequences.IsEmpty()) {
        RandomNum = FMath::RandRange(0, RepeatThatSequences.Max() - 1);
        SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), RepeatThatSequences[RandomNum], PlaybackSettings, OutActor);
        SequencePlayer->Play();
    }
}
void ANursingLevelScript::PlayYes() {
    if (!YesSequences.IsEmpty()) {
        RandomNum = FMath::RandRange(0, YesSequences.Max() - 1);
        SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), YesSequences[RandomNum], PlaybackSettings, OutActor);
        SequencePlayer->Play();
    }
}
void ANursingLevelScript::PlayNo() {
    if (!NoSequences.IsEmpty()) {
        RandomNum = FMath::RandRange(0, NoSequences.Max() - 1);
        SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), NoSequences[RandomNum], PlaybackSettings, OutActor);
        SequencePlayer->Play();
    }
}
void ANursingLevelScript::PlayMaybe() {
    if (MaybeSequence) {
        SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), MaybeSequence, PlaybackSettings, OutActor);
        SequencePlayer->Play();
    }
}
void ANursingLevelScript::PlayBreakfast() {
    if (BreakfastSequence) {
        SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), BreakfastSequence, PlaybackSettings, OutActor);
        SequencePlayer->Play();
    }
}
void ANursingLevelScript::PlayLunch() {
    if (LunchSequence) {
        SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), LunchSequence, PlaybackSettings, OutActor);
        SequencePlayer->Play();
    }
}
void ANursingLevelScript::PlayGreens() {
    if (GreensSequence) {
        SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), GreensSequence, PlaybackSettings, OutActor);
        SequencePlayer->Play();
    }
}

void ANursingLevelScript::ResetPosition()
{
    //Work on this
}



void ANursingLevelScript::AdjustHeight()
{
    //Work on this
}


void ANursingLevelScript::ShowNextHint()
{
    CurrentHintValue = CurrentHintValue + 1;
    UE_LOG(LogTemp, Warning, TEXT("Current Hint Index: %d"), CurrentValue);

    if (CurrentHintValue < LevelSequences.Num()) {
        HintRow = HintTable->FindRow<FHintStructure>(*FString::FromInt(CurrentHintValue), "");

        if (HintRow) {
            UE_LOG(LogTemp, Warning, TEXT("This is the data: %s"), *FString(HintRow->Hint));
            HintUserWidgetEdit->UpdateTitle(FString("Hint"));
            HintUserWidgetEdit->UpdateHint(FString(HintRow->Hint));
        }
    }
}

void ANursingLevelScript::DisplayScript()
{
    
    UE_LOG(LogTemp, Warning, TEXT("Current Script Index: %d"), CurrentValue);

    if (CurrentValue < LevelSequences.Num() && PatientScriptTable) {
        PatientScriptRow = PatientScriptTable->FindRow<FPatientScriptStructure>(*FString::FromInt(CurrentValue+1), "");

        if (PatientScriptRow) {
            UE_LOG(LogTemp, Warning, TEXT("This is the data: %s"), *FString(PatientScriptRow->PatientScript));
            HintUserWidgetEdit->UpdateTitle(FString("Transcript"));
            HintUserWidgetEdit->UpdateHint(FString(PatientScriptRow->PatientScript));
        }
    }
}

void ANursingLevelScript::PlaySequence()
{   
    if (CurrentValue < LevelSequences.Num()) {
        
        CurrentHintValue = CurrentValue + 1;

        SequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), LevelSequences[CurrentValue], PlaybackSettings, OutActor);
        SequencePlayer->Play();

        DisplayScript();
    }
}

void ANursingLevelScript::EndSimulation() {
    UStereoLayerFunctionLibrary::ShowSplashScreen();
    UGameplayStatics::OpenLevel(GetWorld(), "EndSimulation", true);
}

void ANursingLevelScript::ReturnToMainMenu()
{
    //fix this *********
    UStereoLayerFunctionLibrary::ShowSplashScreen();
    UGameplayStatics::OpenLevel(GetWorld(), "MainMenu", true);
}