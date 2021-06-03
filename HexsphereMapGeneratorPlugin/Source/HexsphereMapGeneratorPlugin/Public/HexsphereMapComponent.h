// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "HexsphereMapStructs.h"
#include "HexsphereMapData.h"
#include "HexsphereMapComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, meta=(BlueprintSpawnableComponent))
class HEXSPHEREMAPGENERATORPLUGIN_API UHexsphereMapComponent : public UProceduralMeshComponent
{
	GENERATED_BODY()

private:

	

public:
	UPROPERTY(BlueprintReadWrite)
	UHexsphereMapData* HexsphereMapDataSource;
	UFUNCTION(BlueprintCallable, Category = "Generation")
	void CreateHexsphereMapMesh();
	UFUNCTION(BlueprintCallable, Category = "Generation")
	void UpdateHexsphereMapMesh();
	
};
