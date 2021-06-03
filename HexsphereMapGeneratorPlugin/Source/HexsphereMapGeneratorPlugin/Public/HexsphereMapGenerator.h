// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HexsphereMapStructs.h"
#include "HexsphereMapData.h"
#include "HexsphereMapGenerator.generated.h"

// Represents one of the verts of an icosahedron.
USTRUCT()
struct FIcoVert
{
	GENERATED_BODY()

	UPROPERTY()
	FVector Location;

	// The ID of this ico vert's pentagon.
	UPROPERTY()
	int32 Penta;

	FIcoVert()
	{
		Penta = 0;
		Location = FVector(0.0f, 0.0f, 0.0f);
	}

	FIcoVert(FVector Location, int32 PentagonID)
	{
		this->Location = Location;
		Penta = PentagonID;

	}
};



// An edge of an icosahedron.
USTRUCT()
struct FIcoEdge
{
	GENERATED_USTRUCT_BODY()
	// A and B points of the edge. Unset and unused.
	UPROPERTY()
	int32 A;
	UPROPERTY()
	int32 B;

	UPROPERTY()
	TArray<int32> EdgeHexes;

	FIcoEdge()
	{
		A = 0;
		B = 1;
	}

	FIcoEdge(int32 A, int32 B)
	{
		this->A = A;
		this->B = B;
	}

	FIcoEdge(int32 A, int32 B, TArray<int32> EdgeHexes)
	{
		this->A = A;
		this->B = B;
		this->EdgeHexes = EdgeHexes;
	}
};



// A triangle of an icosahedron.
USTRUCT()
struct FIcoTri
{
	GENERATED_USTRUCT_BODY()
	// Verts.
	UPROPERTY()
	int32 VertA;
	UPROPERTY()
	int32 VertARot;
	UPROPERTY()
	int32 VertB;
	UPROPERTY()
	int32 VertBRot;
	UPROPERTY()
	int32 VertC;
	UPROPERTY()
	int32 VertCRot;

	// Edges.
	UPROPERTY()
	int32 EdgeA;
	UPROPERTY()
	int32 EdgeARot;
	UPROPERTY()
	int32 EdgeB;
	UPROPERTY()
	int32 EdgeBRot;
	UPROPERTY()
	int32 EdgeC;
	UPROPERTY()
	int32 EdgeCRot;

	// Some tris are inverted, these bools are used to accomodate this.
	UPROPERTY()
	bool bBottomEdgeInverted;
	UPROPERTY()
	bool bArmEdgesInverted;

	// IDs of all associated hexes.
	UPROPERTY()
	TArray<int32> TriHexes;

	// Locations of verts.
	UPROPERTY()
	FVector LocA;
	UPROPERTY()
	FVector LocB;
	UPROPERTY()
	FVector LocC;

	// Local XY axes.
	UPROPERTY()
	FVector LocalXAxis;
	UPROPERTY()
	FVector LocalYAxis;

	// Pre-calculated verts of a hexagon in local space.
	UPROPERTY()
	FVector2D HexVertA;
	UPROPERTY()
	FVector2D HexVertB;
	UPROPERTY()
	FVector2D HexVertC;
	UPROPERTY()
	FVector2D HexVertD;

	FIcoTri()
	{
		VertA = 0;
		VertB = 1;
		VertC = 2;

		VertARot = 0;
		VertBRot = 0;
		VertCRot = 0;
	}

	FIcoTri(int32 A, int32 B, int32 C)
	{
		VertA = A;
		VertB = B;
		VertC = C;

		VertARot = 0;
		VertBRot = 0;
		VertCRot = 0;
	}

	void SetEdges(int32 Right, int32 Left, int32 Bottom, bool bInvertArmEdges, bool bInvertBottomEdge)
	{
		EdgeA = Right;
		EdgeB = Left;
		EdgeC = Bottom;
		bBottomEdgeInverted = bInvertBottomEdge;
		bArmEdgesInverted = bInvertArmEdges;
	}

	void SetVertRots(int32 A, int32 B, int32 C)
	{
		VertARot = A;
		VertBRot = B;
		VertCRot = C;
	}

	void SetEdgeRots(int32 A, int32 B, int32 C)
	{
		EdgeARot = A;
		EdgeBRot = B;
		EdgeCRot = C;
	}


};



USTRUCT()
struct FIcoModel
{
	GENERATED_BODY()

	TArray<FIcoVert> IcoVerts;
	TArray<FIcoEdge> IcoEdges;
	TArray<FIcoTri> IcoTris;

	FIcoModel()
	{

	}

};


/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class HEXSPHEREMAPGENERATORPLUGIN_API UHexsphereMapGenerator : public UObject
{
	GENERATED_BODY()

public:

	UHexsphereMapGenerator();

	/**
	 * Generates geometry and hex connection data. Returns an object which contains both.
	 */
	UFUNCTION(BlueprintCallable, Category = "Generation")
	UHexsphereMapData* GenerateHexsphereData(FHexsphereMapGenerationSettings Settings);

private:

	// Initial scale of the icosahedron. Changing this may increase or decrease the accuracy of vertex placement.
	float IcoScale = 1.0f;
	// The model of an icosahedron used by the generator.
	FIcoModel IcoModel;

	// Converts coordinates from local triangle 2D space to world.
	FVector ConvertCoords(FIcoTri& Tri, FVector2D Input, float Radius);
	// Creates 1 out of 12 triangles of a single hex. SideID can be used to override the ID of the tri when handling odd hexes.
	void CreateHexTri(UHexsphereMapData* TargetData, FIcoTri& Tri, FHexsphereMapHexagonData& TargetHex, int32 Side, int32 SideID, bool bFirstHalf, FVector2D PointOfRef);
	// Translates a rotation and makes sure it's not out of bounds.
	int32 RotHex(int32 OriginalPos, int32 Rotation, bool bIsPenta);

	// Sets 2 hexes as neighbours.
	void LinkHexes(UHexsphereMapData* TargetData, int32 HexA, int32 HexB, int32 SideA, int32 SideB);


	// Creates a model of an icosahedron used during the planet generation process.
	void BuildIcoModel();
	// Clears the icosahedron model data. Must be done every generation process to make sure there is no leftover data.
	void ClearIcoModel();
	// Initializes all hexagons.
	void InitHexes(UHexsphereMapData* TargetData);
	// Builds the geometry of a single ico triangle. 
	void BuildTriGeometry(UHexsphereMapData* TargetData, FIcoTri& Tri);
	// Connects the planet hexagons to eachother by determining which side neighbours which hex and with which sides.
	void BuildTriHexConnections(UHexsphereMapData* TargetData, FIcoTri& Tri);

	void GenerateNormals(UHexsphereMapData* TargetData);


};
