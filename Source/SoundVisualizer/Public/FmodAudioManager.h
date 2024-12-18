// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"



#include <memory>

#include "SoundVisualizer/Fmod/soundmanagerfmod.h"

#include "FmodAudioManager.generated.h"


/**
 *
 */


//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSongPlayFinished, const FString& , SongName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE (FSongPlayFinished );

UCLASS(Blueprintable, BlueprintType)
class SOUNDVISUALIZER_API UFmodAudioManager : public UObject
{
	GENERATED_BODY()

    public:
   UFmodAudioManager();
    ~UFmodAudioManager();


    UFUNCTION(BlueprintCallable, Category = "TOOT")
    int32 InitializeManager();

    UFUNCTION(BlueprintCallable, Category = TOOT)
    int32 InitLinerSpectrum(const int32 numBars);

    UFUNCTION(BlueprintCallable, Category = TOOT)
    int32 InitLogSpectrum(const int32 numBars);

    UFUNCTION(BlueprintCallable, Category = TOOT)
    void InitBeatDetector( );

    UFUNCTION(BlueprintCallable, Category = TOOT)
    void FecthLinerSpectrum(TArray<float>& freqValues , const int32 bars);
    UFUNCTION(BlueprintCallable, Category = TOOT)
    void FecthLogSpectrum(TArray<float>& freqValues , const int32 bars);
    UFUNCTION(BlueprintCallable, Category = TOOT)
    void FecthBeat(TArray<float>& freqValues , TArray<float>& freqAverageValues , bool& isBoss , bool& isLowM);
    //
    UFUNCTION(BlueprintCallable, Category = TOOT)
    int32 FetchMediaDuration(const FString& Pathname);



    UFUNCTION(BlueprintCallable, Category = TOOT)
    void UpdFmodSystem();


    UFUNCTION(BlueprintCallable, Category = TOOT)
    int32 PlaySong(const FString &Pathname);
    UFUNCTION(BlueprintCallable, Category = TOOT)
    void StopSong(const FString &Pathname);

    UFUNCTION(BlueprintCallable, Category = TOOT)
    void PauseSong(bool isPause);


    //
    UFUNCTION(BlueprintImplementableEvent, Category = "TOOT")
    void SongPlayEnd(const FString& SongName);
    //
    UFUNCTION( )
    void SongPlayEndFMod();
    //


    // UFUNCTION(BlueprintPure, Category = TOOT)
    // const FString &GetSongName() const;

   // UPROPERTY(BlueprintAssignable, Category="TOOT")  //!!WRONG* property CAN'T be static
    static FSongPlayFinished TootSongPlayEndDelegate;

    static void SongPlayEndEvt( );



    private:

    std::unique_ptr<SoundManagerFmod> mSoundManager;
    FString mCurrSongName;
    FString mOldSongName;
   // std::string oldSongName;
	
};
