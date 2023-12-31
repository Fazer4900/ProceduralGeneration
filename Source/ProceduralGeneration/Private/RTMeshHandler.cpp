// Fill out your copyright notice in the Description page of Project Settings.


#include "RTMeshHandler.h"

RTMeshHandler::RTMeshHandler(URealtimeMeshSimple* realtimeMesh, int chunkCols, int chunkRows, int chunkWidht, int chunkHeight, int  scaleX, int scaleY)
{
	this->realtimeMesh = realtimeMesh;
	this->chunkRows = chunkRows;
	this->chunkCols = chunkCols;
	this->chunkWidht = chunkWidht;
	this->chunkHeight = chunkHeight;
	this->scaleX = scaleX;
	this->scaleY = scaleY;
}

RTMeshHandler::~RTMeshHandler()
{
}

void RTMeshHandler::generateMesh()
{
	int chunkOffsetY = scaleY * (chunkHeight -1 );
	int chunkOffsetX = scaleX * (chunkWidht -1) ;


	for (int y = 0; y < chunkRows; y++)
	{
		for (int x = 0; x < chunkCols; x++)
		{
			FRealtimeMeshSimpleMeshData meshData;
			generateChunkMeshData(meshData, x * chunkOffsetX,y * chunkOffsetY);
			FRealtimeMeshSectionKey StaticSectionKey = realtimeMesh->CreateMeshSection(0, FRealtimeMeshSectionConfig(ERealtimeMeshSectionDrawType::Static, 0), meshData, true);
		}

	}
			

}
void RTMeshHandler::registerMesh()
{
	
}
void RTMeshHandler::generateChunkMeshData(FRealtimeMeshSimpleMeshData& meshData, int chunkIndexX, int chunkIndexY)
{
	TArray<FVector> vertices;
	//GenerateVertices(vertices, chunkWidht, chunkHeight, scaleX, scaleY, 0);
	//
	
	TArray<int32> triangles;
	//GenerateTriangles(triangles, chunkWidht, chunkHeight);
	//

	GenerateVerticesAndTriangles(vertices, triangles, chunkWidht, chunkHeight, scaleX, scaleY, chunkIndexX, chunkIndexY);
	meshData.Positions = vertices;
	meshData.Triangles = triangles;

	const int MeshDataArraysSize = meshData.Positions.Num();
	meshData.Normals.SetNumZeroed(MeshDataArraysSize);
	meshData.Tangents.SetNumZeroed(MeshDataArraysSize);
	meshData.UV0.SetNumZeroed(MeshDataArraysSize);

	
}
FRealtimeMeshSectionKey* RTMeshHandler::registerChunk(FRealtimeMeshSimpleMeshData& meshData)
{
	return nullptr;
}