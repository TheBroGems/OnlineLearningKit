// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TDoor.generated.h"

UCLASS()
class ONLINELEARNINGKIT_API ATDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATDoor();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Door")
	class UStaticMeshComponent* DoorFrameMesh;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Door")
	class UStaticMeshComponent* DoorMesh;

	UFUNCTION(BlueprintCallable,Category="Door")
	void OpenDoor();

	UFUNCTION(BlueprintCallable,Category="Door")
	void CloseDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float SpeedMultiplier = 1.0f;
	
private:
	FVector DoorStartLocation;
	FVector DoorOffset = FVector(0.0f, 170.0f, 0.0f);

	bool bShouldOpen = false;
	float MoveAlpha = 0.0f;
};
