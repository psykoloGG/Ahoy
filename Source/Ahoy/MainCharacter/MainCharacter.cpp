// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"

#include "Blueprint/UserWidget.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Inventory = CreateDefaultSubobject<UInventoryComponent>("Inventory");
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("ForwardBackward", this, &AMainCharacter::ForwardBackwardMovement);
	PlayerInputComponent->BindAxis("StrafeLeftRight", this, &AMainCharacter::LeftRightMovement);
	PlayerInputComponent->BindAxis("LookLeftRight", this, &AMainCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUpDown", this, &AMainCharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAction("InventoryOpen", IE_Released, this, &AMainCharacter::OpenInventory);
}

void AMainCharacter::ForwardBackwardMovement(float Value)
{
	const FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void AMainCharacter::LeftRightMovement(float Value)
{
	const FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

//Fetching and rendering hud to screen
void AMainCharacter::OpenInventory()
{
	FStringClassReference WidgetClassRef(TEXT("/Game/Inventory.Inventory_C"));
	if (UClass* WidgetClass = WidgetClassRef.TryLoadClass<UUserWidget>())
	{
		auto* PlayerController = GetWorld()->GetGameInstance()->GetPrimaryPlayerController();
		
		int X, Y;
		PlayerController->GetViewportSize(X, Y);
		
		UUserWidget* Widget = CreateWidget<UUserWidget>(PlayerController, WidgetClass);
		Widget->SetPositionInViewport(FVector2D(X/2, Y/2));
		Widget->AddToViewport();
		PlayerController->SetInputMode(FInputModeUIOnly());
	}
}

