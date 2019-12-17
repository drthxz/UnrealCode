// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSLauncher.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "FPSCharacter.h"

// Sets default values
AFPSLauncher::AFPSLauncher()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//set mesh
	SkeletaMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletaMeshComp"));
	RootComponent = SkeletaMeshComp;
	SkeletaMeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	//set sphere and set collision
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	SphereComp->SetupAttachment(SkeletaMeshComp);
}

// Called when the game starts or when spawned
void AFPSLauncher::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSLauncher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFPSLauncher::NotifyActorBeginOverlap(AActor * OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), PickUpEffect, GetActorLocation());
	AFPSCharacter* player = Cast<AFPSCharacter>(OtherActor);
	if (player) {
		player->EquipWeapon(this);
		//Destroy();
	}

}

void AFPSLauncher::Exit()
{
	SkeletaMeshComp->SetVisibility(false);
}

