// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSExtractionZone.h"
#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"
#include "FPSGameMode.h"
#include "FPSCharacter.h"

// Sets default values
AFPSExtractionZone::AFPSExtractionZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ExitBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("ExitBoxComp"));
	ExitBoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	ExitBoxComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	ExitBoxComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	ExitBoxComp->SetBoxExtent(FVector(200.f, 200.f, 200.f));
	ExitBoxComp->SetHiddenInGame(false);
	RootComponent = ExitBoxComp;

	DecalComp = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComp"));
	DecalComp->DecalSize = FVector(200.f, 200.f, 200.f);
	DecalComp->SetRelativeRotation(FRotator(90.f, 0.f, 0.f).Quaternion());
	DecalComp->SetupAttachment(ExitBoxComp);

	ExitBoxComp->OnComponentBeginOverlap.AddDynamic(this, &AFPSExtractionZone::HandleOverlap);
}

void AFPSExtractionZone::HandleOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	APawn* player = Cast<APawn>(OtherActor);
	if (nullptr) {
		return;
	}

	

	
	AFPSCharacter* playerchara = Cast<AFPSCharacter>(OtherActor);
	if (playerchara && playerchara->IsCarryingObjective) {
		AFPSGameMode* GM = Cast<AFPSGameMode>(UGameplayStatics::GetGameMode(this));
		if (GM) {
			GM->CompleteMission(player,true);
		}
		UGameplayStatics::SpawnSound2D(this, SuccessSound);
		playerchara->Exit();
	}
	
}

// Called when the game starts or when spawned
void AFPSExtractionZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSExtractionZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

