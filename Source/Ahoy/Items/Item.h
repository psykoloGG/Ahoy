// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

/**
 * Base Item class
 */
UCLASS(Abstract, BlueprintType, Blueprintable, DefaultToInstanced)
class AHOY_API UItem : public UObject
{
	GENERATED_BODY()

public:
	UItem();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FString Desc;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int32 MaxStackSize = 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	bool Usable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UTexture2D* Icon;
};
