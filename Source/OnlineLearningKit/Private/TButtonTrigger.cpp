// Fill out your copyright notice in the Description page of Project Settings.


#include "TButtonTrigger.h"

#include "Components/BoxComponent.h"
#include "Components/Button.h"
#include "TDoor.h"
#include "GameFramework/Character.h"

// Sets default values
ATButtonTrigger::ATButtonTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	ButtonFrameMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ButtonFrame"));
	ButtonFrameMesh->SetupAttachment(RootComponent);

	Button = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Button"));
	Button->SetupAttachment(ButtonFrameMesh);

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetupAttachment(RootComponent);
	TriggerBox->SetBoxExtent(FVector(50.f, 50.f, 50.f));
	TriggerBox->SetCollisionProfileName(TEXT("Trigger"));
	
}

// Called when the game starts or when spawned
void ATButtonTrigger::BeginPlay()
{
	Super::BeginPlay();

	ButtonStartLocation = Button->GetRelativeLocation();
	
	if (TriggerBox)
	{
		TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ATButtonTrigger::OnTriggerBeginOverlap);
	}
	
}

void ATButtonTrigger::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Display, TEXT("Button Trigger Begin Overlap"));
	
	if (!OtherActor || !OtherActor->IsA<ACharacter>())
		return;

	FVector PressedLocation = ButtonStartLocation;
	PressedLocation.Z -= 10.f;
	Button->SetRelativeLocation(PressedLocation);

	if (DoorActor)
	{
		UE_LOG(LogTemp, Display, TEXT("Calling Open Door"));
		DoorActor->OpenDoor();
	}
}


// Called every frame
void ATButtonTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

