// Fill out your copyright notice in the Description page of Project Settings.


#include "GenerationLibrary.h"


void GenerateVertices(TArray<FVector>& vertices,int width, int height, int scaleX, int scaleY, int chunkOffsetX,int chunkOffSetY)
{
	UWorld* World = GEngine->GetWorldContexts()[0].World();
	vertices.SetNum(width * height);
	
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				vertices.Push(FVector(x * scaleX, y * scaleY, 0));
				DrawDebugSphere(World, FVector(x * scaleX, y * scaleY, 0), 25.0f, 16, FColor::Red, true, -1.0f, 0U, 0.0f);			
			}
		}		
}

void GenerateVerticesAndTriangles(TArray<FVector>& vertices, TArray<int32>& triangles, int width, int height, int scaleX, int scaleY, int chunkOffsetX, int chunkOffSetY)
{
	//vertices.SetNum(width * height);
	//triangles.SetNum((width - 1) * (height - 1) * 6);
	int vertex = 0;
		
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			vertices.Push(FVector(x * scaleX + chunkOffsetX, y * scaleY + chunkOffSetY, 0));			
		

			if (y < height - 1 && x < width - 1)
			{
				triangles.Add(vertex);
				triangles.Add(vertex + width);
				triangles.Add(vertex + width + 1);
				triangles.Add(vertex);
				triangles.Add(vertex + width + 1);
				triangles.Add(vertex + 1);			
			
			}

			vertex++;
		}
	}


}

void GenerateTriangles(TArray<int32>& triangles,int width, int height)
{	
	triangles.SetNum(((width - 1) * (height - 1) * 6));	
	int vertex = 0;

	for (int y = 0; y < height -1; y++)
	{
		for (int x = 0; x < width -1; x++)
		{
			triangles.Add(vertex);
			triangles.Add(vertex + width);
			triangles.Add(vertex + width + 1);
			triangles.Add(vertex);
			triangles.Add(vertex + width + 1);
			triangles.Add(vertex + 1);
			
		}
		vertex ++;		
	}
	
	
	
	
}

