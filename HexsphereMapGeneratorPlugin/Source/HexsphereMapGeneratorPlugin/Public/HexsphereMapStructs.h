// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HexsphereMapStructs.generated.h"


USTRUCT(BlueprintType)
struct FTestStructLmao
{
	GENERATED_USTRUCT_BODY()
		//FText TypeName;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FVector2D> TexCoords;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bRandomizeFlip = false;

	FTestStructLmao()
	{
	};

};

// Procedural mesh data structure.
USTRUCT(BlueprintType)
struct FHexsphereMapMeshData
{
	GENERATED_USTRUCT_BODY()

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

	};

};

// Stores all data for a single hexagon.
USTRUCT(BlueprintType)
struct FHexsphereMapHexagonData
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Data")
		TArray<int32> Neighbours;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Data")
		TArray<int32> NeighbourFace;
	/*
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Data")
		TArray<FVector> Verts;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Data")
		TArray<int32> Tris;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Data")
		TArray<FVector> Normals;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Texture Data")
		TArray<FVector2D> UV0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Texture Data")
		TArray<FVector2D> UV1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Texture Data")
		TArray<FVector2D> UV2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Texture Data")
		TArray<FVector2D> UV3;
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Data")
		int32 Address;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Data")
		bool bIsPenta = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Data")
		int32 TerrainType = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Data")
		bool bIsLand = false;

	TArray<bool> Rivers;

	UPROPERTY()
		float Height = 0.0f;
	UPROPERTY()
		float Temperature = 0.0f;
	UPROPERTY()
		float Humidity = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Data")
		int32 RegionID = -1;

	uint8 TypeID = 0;
	// Not used currently.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Data")
		TArray<int32> TextureIDs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hex Data")
		FVector Location;

	void BaseInit()
	{
		/*
		Verts.SetNum(24, true);
		Tris.SetNum(36, true);
		Normals.SetNum(24, true);
		UV0.SetNum(24, true);
		UV1.SetNum(24, true);
		UV2.SetNum(24, true);
		UV3.SetNum(24, true);
		*/
		Neighbours.Init(0, 6);
		NeighbourFace.Init(0, 6);
		TextureIDs.Init(0, 6);
		Rivers.Init(false, 6);
	}

	FHexsphereMapHexagonData()
	{
		BaseInit();
	};

	FHexsphereMapHexagonData(int32 ID)
	{
		BaseInit();
		Address = ID;
	};

	void SetNeighbour(int32 NeighbourAddress, int32 OurSide, int32 NeighbourSide)
	{
		Neighbours[OurSide] = NeighbourAddress;
		NeighbourFace[OurSide] = NeighbourSide;
	}


};

USTRUCT(BlueprintType)
struct FHexsphereMapGenerationSettings
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite)
	int32 Resolution = 30;
	UPROPERTY(BlueprintReadWrite)
	float Radius = 200.0f;
	UPROPERTY(BlueprintReadWrite)
	int32 Seed = 0;
	UPROPERTY(BlueprintReadWrite)
	float RegionStartPointChance = 0.15f;

	//FGradNoiseGenSettings LandmassGenNoiseSettings = FGradNoiseGenSettings();
	UPROPERTY(BlueprintReadWrite)
	FName SurfaceMaterialName = FName(TEXT("TestPlanetMaterial"));
	UPROPERTY(BlueprintReadWrite)
	FName RegionMaterialName = FName(TEXT("TestRegionMaterial"));

	UPROPERTY(BlueprintReadWrite)
	TArray<FName> TypeMapping = { TEXT("Sea"),TEXT("Temperate"),TEXT("Arctic"),TEXT("Desert") };

	FHexsphereMapGenerationSettings()
	{
		SurfaceMaterialName = FName(TEXT("TestPlanetMaterial"));
		RegionMaterialName = FName(TEXT("TestRegionMaterial"));
	};

};

/**
 * 
 */
//UCLASS()
//class HEXSPHEREMAPGENERATORPLUGIN_API UHexsphereMapStructs : public UObject
//{
//	GENERATED_BODY()
//	
//};
