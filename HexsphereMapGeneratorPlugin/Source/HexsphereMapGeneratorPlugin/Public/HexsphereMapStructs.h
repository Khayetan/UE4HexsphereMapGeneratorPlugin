// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HexsphereMapStructs.generated.h"


/**
 * Procedural mesh data structure.
 */
USTRUCT(BlueprintType)
struct FHexsphereMapMeshData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	TArray<FVector> Verts;
	UPROPERTY(BlueprintReadWrite)
	TArray<int32> Tris;
	UPROPERTY(BlueprintReadWrite)
	TArray<FVector> Normals;
	UPROPERTY(BlueprintReadWrite)
	TArray<FVector2D> UV0;
	UPROPERTY(BlueprintReadWrite)
	TArray<FVector2D> UV1;
	UPROPERTY(BlueprintReadWrite)
	TArray<FVector2D> UV2;
	UPROPERTY(BlueprintReadWrite)
	TArray<FVector2D> UV3;

	FHexsphereMapMeshData()
	{

	}

};


/**
 * Stores all data for a single hexagon.
 */
USTRUCT(BlueprintType)
struct FHexsphereMapHexagonData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Data")
	TArray<int32> Neighbours;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Data")
	TArray<int32> NeighbourFace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Data")
	int32 Address;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Data")
	bool bIsPenta = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Data")
	FVector Location;

	void BaseInit()
	{
		Neighbours.Init(0, 6);
		NeighbourFace.Init(0, 6);
	}

	FHexsphereMapHexagonData()
	{
		BaseInit();
	}

	FHexsphereMapHexagonData(int32 ID)
	{
		BaseInit();
		Address = ID;
	}

	void SetNeighbour(int32 NeighbourAddress, int32 OurSide, int32 NeighbourSide)
	{
		Neighbours[OurSide] = NeighbourAddress;
		NeighbourFace[OurSide] = NeighbourSide;
	}

};


/**
 * 
 */
USTRUCT(BlueprintType)
struct FHexsphereMapGenerationSettings
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	int32 Resolution = 30;
	UPROPERTY(BlueprintReadWrite)
	float Radius = 200.0f;

	FHexsphereMapGenerationSettings()
	{

	}

};

