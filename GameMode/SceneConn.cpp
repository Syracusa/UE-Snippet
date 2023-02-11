// Copyright Epic Games, Inc. All Rights Reserved.

#include "MySceneComponent.h"
#include "MyProject4GameModeBase.h"

AMyProject4GameModeBase::AMyProject4GameModeBase()
{
     UMySceneComponent* MySceneComponent = CreateDefaultSubobject<UMySceneComponent>(TEXT("RootComponent"));
     RootComponent = MySceneComponent;
}