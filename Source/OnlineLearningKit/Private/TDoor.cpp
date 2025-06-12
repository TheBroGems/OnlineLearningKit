// Fill out your copyright notice in the Description page of Project Settings.


#include "TDoor.h"

// Sets default values
ATDoor::ATDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	DoorFrameMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	DoorFrameMesh->SetupAttachment(RootComponent);

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	DoorMesh->SetupAttachment(RootComponent);

}

void ATDoor::OpenDoor()
{
	FVector NewDoorLocation = DoorStartLocation + FVector(0, 0, 200);
	DoorMesh->SetRelativeLocation(NewDoorLocation);
}

// Called when the game starts or when spawned
void ATDoor::BeginPlay()
{
	Super::BeginPlay();

	if (DoorMesh)
	{
		DoorStartLocation = DoorMesh->GetRelativeLocation();
	}
}

// Called every frame
void ATDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

