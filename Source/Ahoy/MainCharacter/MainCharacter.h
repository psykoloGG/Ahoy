// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryComponent.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()
class AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void ForwardBackwardMovement(float Value);

	UFUNCTION()
	void LeftRightMovement(float Value);

	UFUNCTION()
	void OpenInventory();

	//Inventory component storing all inventory mechanics
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInventoryComponent* Inventory;
};
