// Fill out your copyright notice in the Description page of Project Settings.


#include "RTMeshActor.h"



ARTMeshActor::ARTMeshActor()
{
	
}

void ARTMeshActor::initComponents()
{
	
}

void ARTMeshActor::BeginPlay()
{
	Super::BeginPlay();

	rtMesh = GetRealtimeMeshComponent()->InitializeRealtimeMesh<URealtimeMeshSimple>();
	meshHandler = new RTMeshHandler(rtMesh, 0, 0, 1000, 1000, 100, 100);
	meshHandler->generateMesh();
	

}

void ARTMeshActor::OnGenerateMesh_Implementation()
{
	Super::OnGenerateMesh_Implementation();

	rtMesh = GetRealtimeMeshComponent()->InitializeRealtimeMesh<URealtimeMeshSimple>();
	meshHandler = new RTMeshHandler(rtMesh, 0, 0, 100, 100, 100, 100);
	meshHandler->generateMesh();
}


void ARTMeshActor::generateMesh()
{	
	meshHandler->generateMesh();
}

ARTMeshActor::~ARTMeshActor()
{

}