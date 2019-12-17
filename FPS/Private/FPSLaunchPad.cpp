// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSLaunchPad.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"

// Sets default values
AFPSLaunchPad::AFPSLaunchPad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("padComp"));
	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &AFPSLaunchPad::OnOverlap);
	OverlapComp->SetBoxExtent(FVector(200.f, 200.f, 20.f));
	OverlapComp->SetHiddenInGame(false);
	RootComponent = OverlapComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);

	launchAngle = 35.f;
	launchForce = 1500.f;
}

void AFPSLaunchPad::OnOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	FRotator launchRotator = GetActorRotation();
	launchRotator.Pitch += launchAngle;
	FVector launchDirection = launchRotator.Vector()*launchForce;
	ACharacter* otherCharacer = Cast<ACharacter>(OtherActor);
	if (otherCharacer) {
		otherCharacer->LaunchCharacter(launchDirection, true, true);
	}
	else if (OtherComp && OtherComp->IsSimulatingPhysics()) {
		OtherComp->AddImpulse(launchDirection, NAME_None, true);
	}
}
