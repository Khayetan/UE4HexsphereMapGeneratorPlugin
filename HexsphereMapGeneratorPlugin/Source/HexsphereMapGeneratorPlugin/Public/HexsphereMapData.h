// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HexsphereMapStructs.h"
#include "HexsphereMapData.generated.h"


struct FHexsphereMapMeshData;
struct FHexsphereMapHexagonData;
/**
 * 
 */

// Formerly FPlanet
UCLASS(Blueprintable, BlueprintType)
class HEXSPHEREMAPGENERATORPLUGIN_API UHexsphereMapData : public UObject
{
	GENERATED_BODY()

	UHexsphereMapData();
public:
	//UPROPERTY(BlueprintReadWrite)
	//TArray<FPlanetRegion> Regions;

	// Contains connection data.
	UPROPERTY(BlueprintReadWrite)
	TArray<FHexsphereMapHexagonData> Hexes;
	// Contains geometry data.
	UPROPERTY(BlueprintReadWrite)
	FHexsphereMapMeshData Geometry;


	//UPROPERTY(BlueprintReadWrite)
	//FProcMeshData RegionMeshData;
	UPROPERTY(BlueprintReadWrite)
	int32 Resolution;
	UPROPERTY(BlueprintReadWrite)
	float Radius;
	UPROPERTY(BlueprintReadWrite)
	int32 HexAmount;

	UPROPERTY(BlueprintReadWrite)
	FName PresetName;

	UPROPERTY(BlueprintReadWrite)
	FName SurfaceMaterialName;
	UPROPERTY(BlueprintReadWrite)
	FName RegionMaterialName;

	UPROPERTY(BlueprintReadWrite)
	TArray<FName> TypeMapping;


	// A function for copying mesh data from a single side of a hexagon.
	FHexsphereMapMeshData GetHexSideMeshData(int32 HexID, int32 SideID);

	// Set the uv coords of a single hex triangle.
	UFUNCTION(BlueprintCallable, Category = "Generation")
	void SetHexTriTexture(int32 HexID, int32 SideID, int32 UVLayer, FVector2D Coords, int32 AtlasResolution, bool bFlip);
	// Set the uv coords of a hexagon.
	UFUNCTION(BlueprintCallable, Category = "Generation")
	void SetHexTexture(int32 HexID, int32 UVLayer, FVector2D Coords, int32 AtlasResolution);
	// Returns the location of the middle vert, the middle of the hexagon.
	FVector GetHexMiddlePoint(int32 HexID);


};
