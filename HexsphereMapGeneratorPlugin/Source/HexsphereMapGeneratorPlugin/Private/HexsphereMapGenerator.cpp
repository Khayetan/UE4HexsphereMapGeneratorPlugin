// Fill out your copyright notice in the Description page of Project Settings.


#include "HexsphereMapGenerator.h"

UHexsphereMapGenerator::UHexsphereMapGenerator()
{

}

void UHexsphereMapGenerator::ClearIcoModel()
{
	IcoModel = FIcoModel();
}

void UHexsphereMapGenerator::BuildIcoModel()
{
	// Init/clear ico model struct.
	ClearIcoModel();

	// Initialize ico arrays.
	IcoModel.IcoVerts.SetNum(12, true);
	IcoModel.IcoEdges.SetNum(30, true);
	IcoModel.IcoTris.SetNum(20, true);

	// Define verts. Pre-calculated values. Accurate enough.
	IcoModel.IcoVerts[0].Location = FVector(0.52572f, -0.7236f, 0.447215f) * IcoScale;
	IcoModel.IcoVerts[1].Location = FVector(-0.52572f, -0.7236f, 0.447215f) * IcoScale;
	IcoModel.IcoVerts[2].Location = FVector(-0.85064f, 0.276385f, 0.447215f) * IcoScale;
	IcoModel.IcoVerts[3].Location = FVector(0.0f, 0.894425f, 0.447215f) * IcoScale;
	IcoModel.IcoVerts[4].Location = FVector(0.85064f, 0.276385f, 0.447215f) * IcoScale;
	IcoModel.IcoVerts[5].Location = FVector(0.0f, 0.0f, 1.0f) * IcoScale;
	IcoModel.IcoVerts[6].Location = FVector(0.0f, -0.894425f, -0.447215f) * IcoScale;
	IcoModel.IcoVerts[7].Location = FVector(-0.85064f, -0.276385f, -0.447215f) * IcoScale;
	IcoModel.IcoVerts[8].Location = FVector(-0.52572f, 0.7236f, -0.447215f) * IcoScale;
	IcoModel.IcoVerts[9].Location = FVector(0.52572f, 0.7236f, -0.447215f) * IcoScale;
	IcoModel.IcoVerts[10].Location = FVector(0.85064f, -0.276385f, -0.447215f) * IcoScale;
	IcoModel.IcoVerts[11].Location = FVector(0.0f, 0.0f, -1.0f) * IcoScale;

	// Define the triangles.
	IcoModel.IcoTris[0] = FIcoTri(1, 5, 0);
	IcoModel.IcoTris[1] = FIcoTri(2, 5, 1);
	IcoModel.IcoTris[2] = FIcoTri(3, 5, 2);
	IcoModel.IcoTris[3] = FIcoTri(4, 5, 3);
	IcoModel.IcoTris[4] = FIcoTri(0, 5, 4);

	IcoModel.IcoTris[5] = FIcoTri(6, 11, 7);
	IcoModel.IcoTris[6] = FIcoTri(7, 11, 8);
	IcoModel.IcoTris[7] = FIcoTri(8, 11, 9);
	IcoModel.IcoTris[8] = FIcoTri(9, 11, 10);
	IcoModel.IcoTris[9] = FIcoTri(10, 11, 6);

	IcoModel.IcoTris[10] = FIcoTri(0, 6, 1);
	IcoModel.IcoTris[11] = FIcoTri(1, 7, 2);
	IcoModel.IcoTris[12] = FIcoTri(2, 8, 3);
	IcoModel.IcoTris[13] = FIcoTri(3, 9, 4);
	IcoModel.IcoTris[14] = FIcoTri(4, 10, 0);

	IcoModel.IcoTris[15] = FIcoTri(7, 1, 6);
	IcoModel.IcoTris[16] = FIcoTri(8, 2, 7);
	IcoModel.IcoTris[17] = FIcoTri(9, 3, 8);
	IcoModel.IcoTris[18] = FIcoTri(10, 4, 9);
	IcoModel.IcoTris[19] = FIcoTri(6, 0, 10);

	// Assign edges to triangles.
	IcoModel.IcoTris[0].SetEdges(1, 0, 10, false, false);
	IcoModel.IcoTris[1].SetEdges(2, 1, 11, false, false);
	IcoModel.IcoTris[2].SetEdges(3, 2, 12, false, false);
	IcoModel.IcoTris[3].SetEdges(4, 3, 13, false, false);
	IcoModel.IcoTris[4].SetEdges(0, 4, 14, false, false);

	IcoModel.IcoTris[5].SetEdges(5, 6, 15, false, false);
	IcoModel.IcoTris[6].SetEdges(6, 7, 16, false, false);
	IcoModel.IcoTris[7].SetEdges(7, 8, 17, false, false);
	IcoModel.IcoTris[8].SetEdges(8, 9, 18, false, false);
	IcoModel.IcoTris[9].SetEdges(9, 5, 19, false, false);

	IcoModel.IcoTris[10].SetEdges(20, 21, 10, true, true);
	IcoModel.IcoTris[11].SetEdges(22, 23, 11, true, true);
	IcoModel.IcoTris[12].SetEdges(24, 25, 12, true, true);
	IcoModel.IcoTris[13].SetEdges(26, 27, 13, true, true);
	IcoModel.IcoTris[14].SetEdges(28, 29, 14, true, true);

	IcoModel.IcoTris[15].SetEdges(22, 21, 15, false, true);
	IcoModel.IcoTris[16].SetEdges(24, 23, 16, false, true);
	IcoModel.IcoTris[17].SetEdges(26, 25, 17, false, true);
	IcoModel.IcoTris[18].SetEdges(28, 27, 18, false, true);
	IcoModel.IcoTris[19].SetEdges(20, 29, 19, false, true);

	// Define rotations, the number represents counter-clockwise rotation of the hex/pentagon.
	// The "-" represents clockwise rotation.
	for (int i = 0; i < 5; i++) // It's faster to loop, this covers the top and bottom tris.
	{
		IcoModel.IcoTris[i].SetVertRots(1, -i, 0);
		IcoModel.IcoTris[i + 5].SetVertRots(1, i, 0);

		IcoModel.IcoTris[i].SetEdgeRots(1, 0, 0);
		IcoModel.IcoTris[i + 5].SetEdgeRots(1, 0, 0);
	}
	for (int i = 0; i < 5; i++) // This covers the tris that have inverted arms and bases.
	{
		IcoModel.IcoTris[i + 10].SetVertRots(3, 0, -2);
		IcoModel.IcoTris[i + 10].SetEdgeRots(-2, 3, 3);
	}
	for (int i = 0; i < 5; i++) // This covers the tris that only have inverted bases.
	{
		IcoModel.IcoTris[i + 15].SetVertRots(3, 0, -2);
		IcoModel.IcoTris[i + 15].SetEdgeRots(1, 0, 3);
	}

}

void UHexsphereMapGenerator::InitHexes(UHexsphereMapData* TargetData)
{
	int32 NextHexID = 0;
	// Calculate the amount of hexes inside a pyramid of a single ico triangle.
	int32 TriHexAmount = 0;
	for (int i = 0; i < (TargetData->Resolution - 1); i++)
	{
		TriHexAmount += TargetData->Resolution - 1 - i;
	}
	// 12 = number of verts, 30 = number of edges, 20 = number of triangles.
	TargetData->HexAmount = 12 + (30 * TargetData->Resolution) + (TriHexAmount * 20);
	TargetData->Hexes.SetNum(TargetData->HexAmount, true);

	// Initialize all vert and edge hexes.
	// Verts.
	for (int i = 0; i < 12; i++)
	{
		TargetData->Hexes[NextHexID] = FHexsphereMapHexagonData(NextHexID);
		TargetData->Hexes[NextHexID].bIsPenta = true;
		IcoModel.IcoVerts[i].Penta = NextHexID;
		NextHexID++;
	}
	// Edges.
	for (int i = 0; i < 30; i++)
	{
		IcoModel.IcoEdges[i].EdgeHexes.SetNum(TargetData->Resolution, false);

		for (int j = 0; j < TargetData->Resolution; j++)
		{
			TargetData->Hexes[NextHexID] = FHexsphereMapHexagonData(NextHexID);
			IcoModel.IcoEdges[i].EdgeHexes[j] = NextHexID;
			NextHexID++;
		}
	}
	// Initialize the hex pyramid inside each triangle.
	for (int i = 0; i < 20; i++)
	{
		int32 PyramidNextIndex = 0;
		IcoModel.IcoTris[i].TriHexes.Init(0, TriHexAmount);

		for (int x = 0; x < TargetData->Resolution - 1; x++)
		{
			for (int y = 0; y < TargetData->Resolution - 1 - x; y++)
			{
				// Init new hex.
				TargetData->Hexes[NextHexID] = FHexsphereMapHexagonData(NextHexID);
				// Link the hex to it's place on the pyramid.
				IcoModel.IcoTris[i].TriHexes[PyramidNextIndex] = NextHexID;
				NextHexID++;
				PyramidNextIndex++;
			}
		}
	}
}

FVector UHexsphereMapGenerator::ConvertCoords(FIcoTri& Tri, FVector2D Input, float Radius)
{
	// Calculate the new location in local space.
	FVector NewLoc = ((Tri.LocalXAxis * Input.X) + (Tri.LocalYAxis * Input.Y) + Tri.LocC);
	NewLoc.Normalize();
	NewLoc = NewLoc * Radius;
	/*
	// Used for debugging to see how the icosahedron looks.
	if (bMakeSpherical)
	{

	}
	*/
	return NewLoc;
};

void UHexsphereMapGenerator::CreateHexTri(UHexsphereMapData* TargetData, FIcoTri& Tri, FHexsphereMapHexagonData& TargetHex, int32 Side, int32 SideID, bool bFirstHalf, FVector2D PointOfRef)
{
	// Address of the target hex used to determine the data placement on arrays.
	int32 A = TargetHex.Address;
	// The verts.
	FVector Vert0;
	FVector Vert1;
	FVector Vert2;
	FVector Vert3;

	// First half handles the first 3 verts. The other half add just the last one.
	if (bFirstHalf)
	{
		// Calculate the first vert.
		Vert0 = ConvertCoords(Tri, PointOfRef, TargetData->Radius);
		// Calculate the other 2 verts.
		switch (Side)
		{
		case 0:
			Vert1 = ConvertCoords(Tri, FVector2D(Tri.HexVertD.X, -Tri.HexVertD.Y) + PointOfRef, TargetData->Radius);
			Vert2 = ConvertCoords(Tri, FVector2D(Tri.HexVertC.X, -Tri.HexVertC.Y) + PointOfRef, TargetData->Radius);
			break;
		case 1:
			Vert1 = ConvertCoords(Tri, FVector2D(Tri.HexVertB.X, -Tri.HexVertB.Y) + PointOfRef, TargetData->Radius);
			Vert2 = ConvertCoords(Tri, Tri.HexVertA + PointOfRef, TargetData->Radius);
			break;
		case 2:
			Vert1 = ConvertCoords(Tri, Tri.HexVertB + PointOfRef, TargetData->Radius);
			Vert2 = ConvertCoords(Tri, Tri.HexVertC + PointOfRef, TargetData->Radius);
			break;
		case 3:
			Vert1 = ConvertCoords(Tri, FVector2D(Tri.HexVertD.X, Tri.HexVertD.Y) + PointOfRef, TargetData->Radius);
			Vert2 = ConvertCoords(Tri, FVector2D(-Tri.HexVertC.X, Tri.HexVertC.Y) + PointOfRef, TargetData->Radius);
			break;
		case 4:
			Vert1 = ConvertCoords(Tri, FVector2D(-Tri.HexVertB.X, Tri.HexVertB.Y) + PointOfRef, TargetData->Radius);
			Vert2 = ConvertCoords(Tri, FVector2D(-Tri.HexVertA.X, Tri.HexVertA.Y) + PointOfRef, TargetData->Radius);
			break;
		case 5:
			Vert1 = ConvertCoords(Tri, FVector2D(-Tri.HexVertB.X, -Tri.HexVertB.Y) + PointOfRef, TargetData->Radius);
			Vert2 = ConvertCoords(Tri, FVector2D(-Tri.HexVertC.X, -Tri.HexVertC.Y) + PointOfRef, TargetData->Radius);
			break;
		default:
			break;
		}

		// Assign data to hex.
		// Makes no sense for this to be done, duplicates data.
		/*
		Target.Verts[SideID * 4] = Vert0;
		Target.Verts[SideID * 4 + 1] = Vert1;
		Target.Verts[SideID * 4 + 2] = Vert2;

		Target.Tris[SideID * 6] = SideID * 4;
		Target.Tris[SideID * 6 + 1] = SideID * 4 + 1;
		Target.Tris[SideID * 6 + 2] = SideID * 4 + 2;
		*/

		// Assign data to mesh arrays.
		TargetData->Geometry.Verts[SideID * 4 + (A * 24)] = Vert0;
		TargetData->Geometry.Verts[SideID * 4 + (A * 24) + 1] = Vert1;
		TargetData->Geometry.Verts[SideID * 4 + (A * 24) + 2] = Vert2;

		TargetData->Geometry.Tris[SideID * 6 + (A * 36)] = SideID * 4 + (A * 24);
		TargetData->Geometry.Tris[SideID * 6 + (A * 36) + 1] = SideID * 4 + 1 + (A * 24);
		TargetData->Geometry.Tris[SideID * 6 + (A * 36) + 2] = SideID * 4 + 2 + (A * 24);


	}
	else
	{
		switch (Side)
		{
		case 0:
			Vert3 = ConvertCoords(Tri, FVector2D(Tri.HexVertB.X, -Tri.HexVertB.Y) + PointOfRef, TargetData->Radius);
			break;
		case 1:
			Vert3 = ConvertCoords(Tri, Tri.HexVertB + PointOfRef, TargetData->Radius);
			break;
		case 2:
			Vert3 = ConvertCoords(Tri, FVector2D(Tri.HexVertD.X, Tri.HexVertD.Y) + PointOfRef, TargetData->Radius);
			break;
		case 3:
			Vert3 = ConvertCoords(Tri, FVector2D(-Tri.HexVertB.X, Tri.HexVertB.Y) + PointOfRef, TargetData->Radius);
			break;
		case 4:
			Vert3 = ConvertCoords(Tri, FVector2D(-Tri.HexVertB.X, -Tri.HexVertB.Y) + PointOfRef, TargetData->Radius);
			break;
		case 5:
			Vert3 = ConvertCoords(Tri, FVector2D(Tri.HexVertD.X, -Tri.HexVertD.Y) + PointOfRef, TargetData->Radius);
			break;
		default:
			break;
		}

		// Assign data to main arrays if debug is on.
		TargetData->Geometry.Verts[SideID * 4 + (A * 24) + 3] = Vert3;

		TargetData->Geometry.Tris[SideID * 6 + (A * 36) + 3] = SideID * 4 + (A * 24);
		TargetData->Geometry.Tris[SideID * 6 + (A * 36) + 4] = SideID * 4 + 2 + (A * 24);
		TargetData->Geometry.Tris[SideID * 6 + (A * 36) + 5] = SideID * 4 + 3 + (A * 24);


	}
}

int32 UHexsphereMapGenerator::RotHex(int32 OriginalPos, int32 Rotation, bool bIsPenta)
{
	int32 Temp = OriginalPos - Rotation;
	if (!bIsPenta)
	{
		if (Temp > 5)
		{
			Temp -= 6;
		}
		else if (Temp < 0)
		{
			Temp += 6;
		}
	}
	else
	{
		if (Temp > 4)
		{
			Temp -= 5;
		}
		else if (Temp < 0)
		{
			Temp += 5;
		}
	}
	return Temp;
}

void UHexsphereMapGenerator::BuildTriGeometry(UHexsphereMapData* TargetData, FIcoTri& Tri)
{
	// Assign the tri vert locations.
	Tri.LocA = IcoModel.IcoVerts[Tri.VertA].Location;
	Tri.LocB = IcoModel.IcoVerts[Tri.VertB].Location;
	Tri.LocC = IcoModel.IcoVerts[Tri.VertC].Location;

	// Calculate local axes.
	Tri.LocalXAxis = Tri.LocA - Tri.LocC;
	Tri.LocalXAxis.Normalize();
	Tri.LocalYAxis = Tri.LocB - FMath::Lerp(Tri.LocC, Tri.LocA, 0.5f);
	Tri.LocalYAxis.Normalize();

	// Calculate hexagon verts.
	// Calculate hex scale.
	float HexHalfWidth = 8.66f;
	float IcoTriBaseLength = (Tri.LocA - Tri.LocC).Size();
	float IcoTriHeight = (IcoTriBaseLength * sqrt(3.0f)) / 2.0f;
	float HexScale = ((Tri.LocA - Tri.LocC).Size() / (float)((TargetData->Resolution + 1) * 2.0f)) / HexHalfWidth;
	// Scale the hex verts.
	Tri.HexVertA = FVector2D(8.66f, 0.0f) * HexScale;
	Tri.HexVertB = FVector2D(8.66f, 5.0f) * HexScale;
	Tri.HexVertC = FVector2D(4.33f, 7.5f) * HexScale;
	Tri.HexVertD = FVector2D(0.0f, 10.0f) * HexScale;

	// Grab the vert pentas.
	FHexsphereMapHexagonData* PentaA = &TargetData->Hexes[IcoModel.IcoVerts[Tri.VertA].Penta];
	FHexsphereMapHexagonData* PentaB = &TargetData->Hexes[IcoModel.IcoVerts[Tri.VertB].Penta];
	FHexsphereMapHexagonData* PentaC = &TargetData->Hexes[IcoModel.IcoVerts[Tri.VertC].Penta];

	// Vert A
	CreateHexTri(TargetData, Tri, (*PentaA), 3, RotHex(3, Tri.VertARot, true), false, FVector2D(IcoTriBaseLength, 0.0f));
	CreateHexTri(TargetData, Tri, (*PentaA), 4, RotHex(4, Tri.VertARot, true), true, FVector2D(IcoTriBaseLength, 0.0f));
	// Vert B
	CreateHexTri(TargetData, Tri, (*PentaB), 5, RotHex(4, Tri.VertBRot, true), false, FVector2D(IcoTriBaseLength / 2.0f, IcoTriHeight));
	CreateHexTri(TargetData, Tri, (*PentaB), 0, RotHex(0, Tri.VertBRot, true), true, FVector2D(IcoTriBaseLength / 2.0f, IcoTriHeight));
	// Vert C
	CreateHexTri(TargetData, Tri, (*PentaC), 1, RotHex(1, Tri.VertCRot, true), false, FVector2D(0.0f, 0.0f));
	CreateHexTri(TargetData, Tri, (*PentaC), 2, RotHex(2, Tri.VertCRot, true), true, FVector2D(0.0f, 0.0f));

	// Fill edges.
	// Get refs to edges.
	FIcoEdge* EdgeA = &IcoModel.IcoEdges[Tri.EdgeA];
	FIcoEdge* EdgeB = &IcoModel.IcoEdges[Tri.EdgeB];
	FIcoEdge* EdgeC = &IcoModel.IcoEdges[Tri.EdgeC];

	// Calculate distances.
	float xDist = IcoTriBaseLength / (float)((TargetData->Resolution + 1) * 2);
	float yDist = IcoTriHeight / (float)(TargetData->Resolution + 1);

	FHexsphereMapHexagonData* Hex;
	FVector2D Offset;

	// Loop through each edge verts.
	for (int32 r = 0; r < TargetData->Resolution; r++)
	{
		// Edge A first.
		// This flips the order of looping if the edges are inverted.
		Hex = Tri.bArmEdgesInverted ? &TargetData->Hexes[EdgeA->EdgeHexes[TargetData->Resolution - 1 - r]] : &TargetData->Hexes[EdgeA->EdgeHexes[r]];

		// Calculate the offset for this hex.
		Offset = FVector2D(IcoTriBaseLength - xDist * (r + 1), yDist * (r + 1));

		CreateHexTri(TargetData, Tri, (*Hex), 3, RotHex(3, Tri.EdgeARot, false), false, Offset);

		CreateHexTri(TargetData, Tri, (*Hex), 4, RotHex(4, Tri.EdgeARot, false), true, Offset);
		CreateHexTri(TargetData, Tri, (*Hex), 4, RotHex(4, Tri.EdgeARot, false), false, Offset);

		CreateHexTri(TargetData, Tri, (*Hex), 5, RotHex(5, Tri.EdgeARot, false), true, Offset);
		CreateHexTri(TargetData, Tri, (*Hex), 5, RotHex(5, Tri.EdgeARot, false), false, Offset);

		CreateHexTri(TargetData, Tri, (*Hex), 0, RotHex(0, Tri.EdgeARot, false), true, Offset);

		// Edge B next.
		// Same thing as above.
		Hex = Tri.bArmEdgesInverted ? &TargetData->Hexes[EdgeB->EdgeHexes[TargetData->Resolution - 1 - r]] : &TargetData->Hexes[EdgeB->EdgeHexes[r]];

		// Calculate the offset for this hex.
		Offset = FVector2D(xDist * (r + 1), yDist * (r + 1));

		CreateHexTri(TargetData, Tri, (*Hex), 5, RotHex(5, Tri.EdgeBRot, false), false, Offset);

		CreateHexTri(TargetData, Tri, (*Hex), 0, RotHex(0, Tri.EdgeBRot, false), true, Offset);
		CreateHexTri(TargetData, Tri, (*Hex), 0, RotHex(0, Tri.EdgeBRot, false), false, Offset);

		CreateHexTri(TargetData, Tri, (*Hex), 1, RotHex(1, Tri.EdgeBRot, false), true, Offset);
		CreateHexTri(TargetData, Tri, (*Hex), 1, RotHex(1, Tri.EdgeBRot, false), false, Offset);

		CreateHexTri(TargetData, Tri, (*Hex), 2, RotHex(2, Tri.EdgeBRot, false), true, Offset);

		// Edge C last.
		// We also need to flip direction here, based on the bottom edge this time.
		Hex = Tri.bBottomEdgeInverted ? &TargetData->Hexes[EdgeC->EdgeHexes[TargetData->Resolution - 1 - r]] : &TargetData->Hexes[EdgeC->EdgeHexes[r]];
		Offset = FVector2D(xDist * 2 * (r + 1), 0.0f);

		CreateHexTri(TargetData, Tri, (*Hex), 1, RotHex(1, Tri.EdgeCRot, false), false, Offset);

		CreateHexTri(TargetData, Tri, (*Hex), 2, RotHex(2, Tri.EdgeCRot, false), true, Offset);
		CreateHexTri(TargetData, Tri, (*Hex), 2, RotHex(2, Tri.EdgeCRot, false), false, Offset);

		CreateHexTri(TargetData, Tri, (*Hex), 3, RotHex(3, Tri.EdgeCRot, false), true, Offset);
		CreateHexTri(TargetData, Tri, (*Hex), 3, RotHex(3, Tri.EdgeCRot, false), false, Offset);

		CreateHexTri(TargetData, Tri, (*Hex), 4, RotHex(4, Tri.EdgeCRot, false), true, Offset);
	}

	// Fill the hex pyramid inside the ico triangle.
	FVector2D PyramidOffset;
	FVector2D PyramidRefPoint;
	int32 TriPyramidCounter = 0;

	for (int x = 0; x < TargetData->Resolution - 1; x++)
	{
		PyramidOffset = FVector2D(3 * xDist + (x * xDist), yDist * (x + 1));

		for (int y = 0; y < TargetData->Resolution - 1 - x; y++)
		{
			// Calculate position.
			PyramidRefPoint = FVector2D(xDist * 2 * y, 0.0f);
			Offset = PyramidOffset + PyramidRefPoint;
			// Grab hex from the triangle.
			Hex = &TargetData->Hexes[Tri.TriHexes[TriPyramidCounter]];
			TriPyramidCounter++;
			// Make geometry.
			CreateHexTri(TargetData, Tri, (*Hex), 0, 0, true, Offset);
			CreateHexTri(TargetData, Tri, (*Hex), 0, 0, false, Offset);

			CreateHexTri(TargetData, Tri, (*Hex), 1, 1, true, Offset);
			CreateHexTri(TargetData, Tri, (*Hex), 1, 1, false, Offset);

			CreateHexTri(TargetData, Tri, (*Hex), 2, 2, true, Offset);
			CreateHexTri(TargetData, Tri, (*Hex), 2, 2, false, Offset);

			CreateHexTri(TargetData, Tri, (*Hex), 3, 3, true, Offset);
			CreateHexTri(TargetData, Tri, (*Hex), 3, 3, false, Offset);

			CreateHexTri(TargetData, Tri, (*Hex), 4, 4, true, Offset);
			CreateHexTri(TargetData, Tri, (*Hex), 4, 4, false, Offset);

			CreateHexTri(TargetData, Tri, (*Hex), 5, 5, true, Offset);
			CreateHexTri(TargetData, Tri, (*Hex), 5, 5, false, Offset);
		}
	}


}

void UHexsphereMapGenerator::LinkHexes(UHexsphereMapData* TargetData, int32 HexA, int32 HexB, int32 SideA, int32 SideB)
{

	TargetData->Hexes[HexA].SetNeighbour(TargetData->Hexes[HexB].Address, SideA, SideB);
	TargetData->Hexes[HexB].SetNeighbour(TargetData->Hexes[HexA].Address, SideB, SideA);
};

void UHexsphereMapGenerator::BuildTriHexConnections(UHexsphereMapData* TargetData, FIcoTri& Tri)
{
	//FIcoTri* t = &IcoTris[0];
	int32 PyramidCounter = 0;
	FHexsphereMapHexagonData* Hex;
	FIcoEdge* EdgeA = &IcoModel.IcoEdges[Tri.EdgeA];
	FIcoEdge* EdgeB = &IcoModel.IcoEdges[Tri.EdgeB];
	FIcoEdge* EdgeC = &IcoModel.IcoEdges[Tri.EdgeC];

	// Link hexes in the pyramid.
	for (int x = 0; x < TargetData->Resolution - 1; x++)
	{
		for (int y = 0; y < TargetData->Resolution - 1 - x; y++)
		{
			Hex = &TargetData->Hexes[Tri.TriHexes[PyramidCounter]];
			PyramidCounter++;

			// First, handle the left and top left connections, also link hexes on the edges.
			if (y == 0)	// 0 means we're at the first hex of the row.
			{
				if (!Tri.bArmEdgesInverted)
				{
					LinkHexes(TargetData, Hex->Address, EdgeB->EdgeHexes[x], 4, RotHex(1, Tri.EdgeBRot, false));
					LinkHexes(TargetData, Hex->Address, EdgeB->EdgeHexes[x + 1], 3, RotHex(0, Tri.EdgeBRot, false));
					LinkHexes(TargetData, EdgeB->EdgeHexes[x], EdgeB->EdgeHexes[x + 1], RotHex(2, Tri.EdgeBRot, false), RotHex(5, Tri.EdgeBRot, false)); //the last line here and below links the hexes on the edges
				}
				else // We need to flip the edge indexes.
				{
					LinkHexes(TargetData, Hex->Address, EdgeB->EdgeHexes[TargetData->Resolution - 1 - x], 4, RotHex(1, Tri.EdgeBRot, false));
					LinkHexes(TargetData, Hex->Address, EdgeB->EdgeHexes[TargetData->Resolution - 2 - x], 3, RotHex(0, Tri.EdgeBRot, false));
					LinkHexes(TargetData, EdgeB->EdgeHexes[TargetData->Resolution - 1 - x], EdgeB->EdgeHexes[TargetData->Resolution - 2 - x], RotHex(2, Tri.EdgeBRot, false), RotHex(5, Tri.EdgeBRot, false));
				}
			}
			else
			{
				Hex->SetNeighbour(Hex->Address - 1, 4, 1);
				Hex->SetNeighbour(Hex->Address + TargetData->Resolution - 2 - x, 3, 0);
			}

			// Now we're doing right and top right.
			if (y == TargetData->Resolution - 2 - x) // If we're at the end of the row.
			{
				if (!Tri.bArmEdgesInverted)
				{
					LinkHexes(TargetData, Hex->Address, EdgeA->EdgeHexes[x], 1, RotHex(4, Tri.EdgeARot, false));
					LinkHexes(TargetData, Hex->Address, EdgeA->EdgeHexes[x + 1], 2, RotHex(5, Tri.EdgeARot, false));
					LinkHexes(TargetData, EdgeA->EdgeHexes[x], EdgeA->EdgeHexes[x + 1], RotHex(3, Tri.EdgeARot, false), RotHex(0, Tri.EdgeARot, false));
				}
				else
				{
					LinkHexes(TargetData, Hex->Address, EdgeA->EdgeHexes[TargetData->Resolution - 1 - x], 1, RotHex(4, Tri.EdgeARot, false));
					LinkHexes(TargetData, Hex->Address, EdgeA->EdgeHexes[TargetData->Resolution - 2 - x], 2, RotHex(5, Tri.EdgeARot, false));
					LinkHexes(TargetData, EdgeA->EdgeHexes[TargetData->Resolution - 1 - x], EdgeA->EdgeHexes[TargetData->Resolution - 2 - x], RotHex(3, Tri.EdgeARot, false), RotHex(0, Tri.EdgeARot, false));
				}
			}
			else
			{
				Hex->SetNeighbour(Hex->Address + 1, 1, 4);
				Hex->SetNeighbour(Hex->Address + TargetData->Resolution - 1 - x, 2, 5);
			}

			// Now bottom left and bottom right.
			if (x == 0) // 'x == 0' means we're on the bottom row.
			{
				if (!Tri.bBottomEdgeInverted)
				{
					LinkHexes(TargetData, Hex->Address, EdgeC->EdgeHexes[y], 5, RotHex(2, Tri.EdgeCRot, false));
					LinkHexes(TargetData, Hex->Address, EdgeC->EdgeHexes[y + 1], 0, RotHex(3, Tri.EdgeCRot, false));
					LinkHexes(TargetData, EdgeC->EdgeHexes[y], EdgeC->EdgeHexes[y + 1], RotHex(1, Tri.EdgeCRot, false), RotHex(4, Tri.EdgeCRot, false));
				}
				else
				{
					LinkHexes(TargetData, Hex->Address, EdgeC->EdgeHexes[TargetData->Resolution - 1 - y], 5, RotHex(2, Tri.EdgeCRot, false));
					LinkHexes(TargetData, Hex->Address, EdgeC->EdgeHexes[TargetData->Resolution - 2 - y], 0, RotHex(3, Tri.EdgeCRot, false));
					LinkHexes(TargetData, EdgeC->EdgeHexes[TargetData->Resolution - 1 - y], EdgeC->EdgeHexes[TargetData->Resolution - 2 - y], RotHex(1, Tri.EdgeCRot, false), RotHex(4, Tri.EdgeCRot, false));
				}

			}
			else
			{
				Hex->SetNeighbour(Hex->Address - (TargetData->Resolution - x), 5, 2);
				Hex->SetNeighbour(Hex->Address - (TargetData->Resolution - x) + 1, 0, 3);
			}

		}
	}

	// Connect vert pentas to edges and last edge hexes to eachother.
	FHexsphereMapHexagonData* VertA = &TargetData->Hexes[IcoModel.IcoVerts[Tri.VertA].Penta];
	FHexsphereMapHexagonData* vertB = &TargetData->Hexes[IcoModel.IcoVerts[Tri.VertB].Penta];
	FHexsphereMapHexagonData* vertC = &TargetData->Hexes[IcoModel.IcoVerts[Tri.VertC].Penta];

	// The first letter is the vert to which we are connecting, the second is the edge from which the hex comes from.
	int32 IndexA_A;
	int32 IndexA_C;

	int32 IndexB_A;
	int32 IndexB_B;

	int32 IndexC_B;
	int32 IndexC_C;

	// Switch the hexes we're grabbing based on the orientation of the triangle.
	if (!Tri.bBottomEdgeInverted)
	{
		IndexA_C = TargetData->Resolution - 1;
		IndexC_C = 0;
	}
	else
	{
		IndexA_C = 0;
		IndexC_C = TargetData->Resolution - 1;
	}

	if (!Tri.bArmEdgesInverted)
	{
		IndexA_A = 0;
		IndexB_A = TargetData->Resolution - 1;
		IndexB_B = TargetData->Resolution - 1;
		IndexC_B = 0;
	}
	else
	{
		IndexA_A = TargetData->Resolution - 1;
		IndexB_A = 0;
		IndexB_B = 0;
		IndexC_B = TargetData->Resolution - 1;
	}

	// Vert A
	// First line connects penta to edge A, next to edge C, last connects A and C to eachother.
	// Same thing happens with the other verts but with different edges.
	LinkHexes(TargetData, VertA->Address, EdgeA->EdgeHexes[IndexA_A], RotHex(3, Tri.VertARot, true), RotHex(0, Tri.EdgeARot, false));
	LinkHexes(TargetData, VertA->Address, EdgeC->EdgeHexes[IndexA_C], RotHex(4, Tri.VertARot, true), RotHex(1, Tri.EdgeCRot, false));
	LinkHexes(TargetData, EdgeA->EdgeHexes[IndexA_A], EdgeC->EdgeHexes[IndexA_C], RotHex(5, Tri.EdgeARot, false), RotHex(2, Tri.EdgeCRot, false));

	// Vert B
	LinkHexes(TargetData, vertB->Address, EdgeA->EdgeHexes[IndexB_A], RotHex(0, Tri.VertBRot, true), RotHex(3, Tri.EdgeARot, false));
	LinkHexes(TargetData, vertB->Address, EdgeB->EdgeHexes[IndexB_B], RotHex(4, Tri.VertBRot, true), RotHex(2, Tri.EdgeBRot, false));
	LinkHexes(TargetData, EdgeA->EdgeHexes[IndexB_A], EdgeB->EdgeHexes[IndexB_B], RotHex(4, Tri.EdgeARot, false), RotHex(1, Tri.EdgeBRot, false));

	// Vert C
	LinkHexes(TargetData, vertC->Address, EdgeB->EdgeHexes[IndexC_B], RotHex(2, Tri.VertCRot, true), RotHex(5, Tri.EdgeBRot, false));
	LinkHexes(TargetData, vertC->Address, EdgeC->EdgeHexes[IndexC_C], RotHex(1, Tri.VertCRot, true), RotHex(4, Tri.EdgeCRot, false));
	LinkHexes(TargetData, EdgeB->EdgeHexes[IndexC_B], EdgeC->EdgeHexes[IndexC_C], RotHex(0, Tri.EdgeBRot, false), RotHex(3, Tri.EdgeCRot, false));

}



void UHexsphereMapGenerator::GenerateNormals(UHexsphereMapData* TargetData)
{
	FVector Normal;
	for (int32 i = 0; i < TargetData->Geometry.Verts.Num(); i++)
	{
		Normal = TargetData->Geometry.Verts[i];
		Normal.Normalize();
		TargetData->Geometry.Normals[i] = Normal;
	}
}




UHexsphereMapData* UHexsphereMapGenerator::GenerateHexsphereData(FHexsphereMapGenerationSettings Settings)
{
	UHexsphereMapData* GeneratedData = NewObject<UHexsphereMapData>();

	GeneratedData->Resolution = Settings.Resolution;
	GeneratedData->Radius = Settings.Radius;

	BuildIcoModel();
	InitHexes(GeneratedData);

	// Init geometry arrays, 24 is the amount of verts a single hex will take, 36 is the number of spaces the tris of the hex will take.
	GeneratedData->Geometry.Verts.Init(FVector(0.0f, 0.0f, 0.0f), GeneratedData->HexAmount * 24);
	GeneratedData->Geometry.Tris.Init(0, GeneratedData->HexAmount * 36);
	GeneratedData->Geometry.Normals.Init(FVector(0.0f, 0.0f, 0.0f), GeneratedData->HexAmount * 24);
	GeneratedData->Geometry.UV0.Init(FVector2D(0.0f, 0.0f), GeneratedData->HexAmount * 24);
	GeneratedData->Geometry.UV1.Init(FVector2D(0.0f, 0.0f), GeneratedData->HexAmount * 24);
	GeneratedData->Geometry.UV2.Init(FVector2D(0.0f, 0.0f), GeneratedData->HexAmount * 24);
	GeneratedData->Geometry.UV3.Init(FVector2D(0.0f, 0.0f), GeneratedData->HexAmount * 24);

	// For each triangle, build geometry and link hexes.
	for (int i = 0; i < 20; i++)
	{
		BuildTriGeometry(GeneratedData, IcoModel.IcoTris[i]);
		BuildTriHexConnections(GeneratedData, IcoModel.IcoTris[i]);
	}

	GenerateNormals(GeneratedData);

	return GeneratedData;
}


