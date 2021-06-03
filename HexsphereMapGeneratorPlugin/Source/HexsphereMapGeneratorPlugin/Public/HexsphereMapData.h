// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HexsphereMapStructs.h"
#include "HexsphereMapData.generated.h"


/**
 * Data object which contains all the information needed to create a hexsphere.
 */
UCLASS(Blueprintable, BlueprintType)
class HEXSPHEREMAPGENERATORPLUGIN_API UHexsphereMapData : public UObject
{
	GENERATED_BODY()

	UHexsphereMapData();

public:
	/** Contains connection data. */
	UPROPERTY(BlueprintReadWrite)
	TArray<FHexsphereMapHexagonData> Hexes;
	/** Contains geometry data. */
	UPROPERTY(BlueprintReadWrite)
	FHexsphereMapMeshData Geometry;

	UPROPERTY(BlueprintReadWrite)
	int32 Resolution;
	UPROPERTY(BlueprintReadWrite)
	float Radius;
	UPROPERTY(BlueprintReadWrite)
	int32 HexAmount;

	/** A function for copying mesh data from a single side of a hexagon. */
	FHexsphereMapMeshData GetHexSideMeshData(int32 HexID, int32 SideID);

	/** Set the UV coords of a single hex triangle. */
	UFUNCTION(BlueprintCallable, Category = "Default")
	void SetHexTriTexture(int32 HexID, int32 SideID, int32 UVLayer, FVector2D Coords, int32 AtlasResolution, bool bFlip);
	/** Set the UV coords of a hexagon. */
	UFUNCTION(BlueprintCallable, Category = "Default")
	void SetHexTexture(int32 HexID, int32 UVLayer, FVector2D Coords, int32 AtlasResolution);
	/** Returns the location of the middle vert, the middle of the hexagon. */
	UFUNCTION(BlueprintCallable, Category = "Default")
	FVector GetHexMiddlePoint(int32 HexID);


};
