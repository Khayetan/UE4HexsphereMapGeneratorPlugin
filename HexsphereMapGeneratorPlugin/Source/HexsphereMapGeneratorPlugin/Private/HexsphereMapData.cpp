// Fill out your copyright notice in the Description page of Project Settings.


#include "HexsphereMapData.h"


UHexsphereMapData::UHexsphereMapData()
{

}


FHexsphereMapMeshData UHexsphereMapData::GetHexSideMeshData(int32 HexID, int32 SideID)
{
	FHexsphereMapMeshData NewData = FHexsphereMapMeshData();
	// Initialize array lenghts.
	NewData.Verts.SetNum(4);
	NewData.Tris.SetNum(6);
	NewData.Normals.SetNum(4);
	NewData.UV0.SetNum(4);
	NewData.UV1.SetNum(4);
	NewData.UV2.SetNum(4);
	NewData.UV3.SetNum(4);

	// Calculate the position on the mesh array.
	int32 VertOffset = (HexID * 24) + (SideID * 4);
	int32 TriOffset = (HexID * 36) + (SideID * 6);
	// Copy vert data.
	for (int32 i = 0; i < 4; i++)
	{
		NewData.Verts[i] = Geometry.Verts[i + VertOffset];
		NewData.Normals[i] = Geometry.Normals[i + VertOffset];
		NewData.UV0[i] = Geometry.UV0[i + VertOffset];
		NewData.UV1[i] = Geometry.UV1[i + VertOffset];
		NewData.UV2[i] = Geometry.UV2[i + VertOffset];
		NewData.UV3[i] = Geometry.UV3[i + VertOffset];
	}

	// IDIOT Copy tri data. MORON
	for (int32 i = 0; i < 6; i++)
	{
		NewData.Tris[i] = Geometry.Tris[i + TriOffset] - VertOffset;
	}


	return NewData;
}





void UHexsphereMapData::SetHexTriTexture(int32 HexID, int32 SideID, int32 UVLayer, FVector2D Coords, int32 AtlasResolution, bool bFlip)
{
	TArray<FVector2D>* TargetUVs;
	FHexsphereMapHexagonData* TargetHex = &Hexes[HexID];
	float CellSize = 1.0f/(float)AtlasResolution;//0.125f;

	switch (UVLayer)
	{
	case 0: TargetUVs = &(Geometry.UV0);
		break;
	case 1: TargetUVs = &(Geometry.UV1);
		break;
	case 2: TargetUVs = &(Geometry.UV2);
		break;
	case 3: TargetUVs = &(Geometry.UV3);
		break;
	default: TargetUVs = &(Geometry.UV0);
	}

	FVector2D Offset = FVector2D(CellSize * Coords.X, CellSize * Coords.Y);

	FVector2D A = FVector2D(CellSize / 2.0f, CellSize) + Offset;
	FVector2D B = FVector2D(CellSize, 0.0f) + Offset;
	FVector2D C = FVector2D(CellSize / 2.0f, 0.0f) + Offset;
	FVector2D D = FVector2D(0.0f, 0.0f) + Offset;

	int32 HexOffset = HexID * 24;

	(*TargetUVs)[SideID * 4 + HexOffset] = A;
	(*TargetUVs)[SideID * 4 + 1 + HexOffset] = bFlip ? D : B;
	(*TargetUVs)[SideID * 4 + 2 + HexOffset] = C;
	(*TargetUVs)[SideID * 4 + 3 + HexOffset] = bFlip ? B : D;

}





void UHexsphereMapData::SetHexTexture(int32 HexID, int32 UVLayer, FVector2D Coords, int32 AtlasResolution)
{
	int32 Length = Hexes[HexID].bIsPenta ? 5 : 6;
	for (int32 i = 0; i < Length; i++)
	{
		SetHexTriTexture(HexID, i, UVLayer, Coords, AtlasResolution, false);
	}
}

FVector UHexsphereMapData::GetHexMiddlePoint(int32 HexID)
{
	return Geometry.Verts[HexID * 24];
}
