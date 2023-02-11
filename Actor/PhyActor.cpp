// Fill out your copyright notice in the Description page of Project Settings.
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"
#include "MyStaticMeshActor.h"

AMyStaticMeshActor::AMyStaticMeshActor()
{
    PrimaryActorTick.bCanEverTick = true;

    UBoxComponent* BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
    RootComponent = BoxComponent;

    UStaticMeshComponent* BoxVisual
        = CreateDefaultSubobject<UStaticMeshComponent>
        (TEXT("VisualRepresentation"));

    BoxVisual->SetupAttachment(RootComponent);
    static ConstructorHelpers::FObjectFinder<UStaticMesh>
        BoxVisualAsset
        (TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

    if (BoxVisualAsset.Succeeded())
    {
        UE_LOG(LogTemp, Warning, TEXT("Get BoxVisualAsset Success`!"));
        BoxVisual->SetStaticMesh(BoxVisualAsset.Object);
        BoxVisual->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
        BoxVisual->SetWorldScale3D(FVector(0.2f));

        BoxVisual->SetSimulatePhysics(true);
        BoxVisual->SetEnableGravity(true);
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("Can't get BoxVisualAsset!"));
    }
}