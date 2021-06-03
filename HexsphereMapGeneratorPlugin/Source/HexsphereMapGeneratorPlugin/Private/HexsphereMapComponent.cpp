// Fill out your copyright notice in the Description page of Project Settings.


#include "HexsphereMapComponent.h"

void UHexsphereMapComponent::CreateHexsphereMapMesh()
{

	TArray<FLinearColor> VertexColors;
	TArray<FProcMeshTangent> Tangents;
	CreateMeshSection_LinearColor(0, HexsphereMapDataSource->Geometry.Verts, HexsphereMapDataSource->Geometry.Tris, HexsphereMapDataSource->Geometry.Normals, HexsphereMapDataSource->Geometry.UV0, HexsphereMapDataSource->Geometry.UV1, HexsphereMapDataSource->Geometry.UV2, HexsphereMapDataSource->Geometry.UV3, VertexColors, Tangents, false);
}

void UHexsphereMapComponent::UpdateHexsphereMapMesh()
{
	TArray<FLinearColor> VertexColors;
	TArray<FProcMeshTangent> Tangents;
	UpdateMeshSection_LinearColor(0, HexsphereMapDataSource->Geometry.Verts, HexsphereMapDataSource->Geometry.Normals, HexsphereMapDataSource->Geometry.UV0, HexsphereMapDataSource->Geometry.UV1, HexsphereMapDataSource->Geometry.UV2, HexsphereMapDataSource->Geometry.UV3, VertexColors, Tangents);
}
