// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSLauncher.generated.h"

class USphereComponent;
class UParticleSystem;

UCLASS()
class FPS_API AFPSLauncher : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "Components")
		USphereComponent* SphereComp;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		USkeletalMeshComponent* SkeletaMeshComp;

	UPROPERTY(EditDefaultsOnly, Category = "FX")
		UParticleSystem* PickUpEffect;

public:	
	// Sets default values for this actor's properties
	AFPSLauncher();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor);
	void Exit();
};
