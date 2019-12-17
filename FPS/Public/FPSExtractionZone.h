// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "FPSExtractionZone.generated.h"

class UBoxComponent;


UCLASS()
class FPS_API AFPSExtractionZone : public AActor
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnyWhere, Category = "Components")
		UBoxComponent* ExitBoxComp;
	UPROPERTY(VisibleAnyWhere, Category = "Components")
		UDecalComponent* DecalComp;
	UPROPERTY(EditDefaultsOnly, Category = "Components")
		USoundBase* SuccessSound;
	
public:	
	// Sets default values for this actor's properties
	AFPSExtractionZone();

	UFUNCTION()
		void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
