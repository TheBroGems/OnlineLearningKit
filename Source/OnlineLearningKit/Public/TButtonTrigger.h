// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TButtonTrigger.generated.h"

class UStaticMeshComponent;
class UBoxComponent;
class ATDoor;

UCLASS()
class ONLINELEARNINGKIT_API ATButtonTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATButtonTrigger();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Button")
	UStaticMeshComponent* ButtonFrameMesh;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Button")
	UStaticMeshComponent* Button;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Button")
	UBoxComponent* TriggerBox;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Button")
	ATDoor* DoorActor;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnTriggerBeginOverlap
	(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
		);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector ButtonStartLocation;
};
