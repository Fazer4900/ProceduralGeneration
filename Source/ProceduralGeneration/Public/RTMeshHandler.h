// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RealtimeMeshSimple.h"
#include "GenerationLibrary.h"

/**
 * 
 */
class PROCEDURALGENERATION_API RTMeshHandler
{
public:

	//init of RTMeshHandler
	RTMeshHandler(URealtimeMeshSimple* RealtimeMesh, int chunkIndexX, int chunkIndexY, int chunkWidht, int chunkHeight, int  scaleX, int scaleY);

	void generateMesh();
	void registerMesh();

	void generateChunkMeshData(FRealtimeMeshSimpleMeshData& meshdata,int chunkIndexX,int chunkIndexY);
	FRealtimeMeshSectionKey* registerChunk(FRealtimeMeshSimpleMeshData & meshData);

	~RTMeshHandler();

private:

	URealtimeMeshSimple* realtimeMesh;

	int chunkCols = 0;
	int chunkRows = 0;
	int chunkWidht = 0;
	int chunkHeight = 0;
	int scaleX = 0;
	int scaleY = 0;
};
