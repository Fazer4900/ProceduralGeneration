// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"



//function for generating vertices in mesh
void GenerateVertices(TArray<FVector>& vertices, int width, int height, int scaleX, int scaleY, int chunkOffsetX, int chunkOffSetY);
void GenerateTriangles(TArray<int32>& triangles, int widht, int height);
void GenerateVerticesAndTriangles(TArray<FVector>& vertices, TArray<int32>& triangles, int width, int height, int scaleX, int scaleY, int chunkOffsetX, int chunkOffSetY);


