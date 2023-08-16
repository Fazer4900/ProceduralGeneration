// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RealtimeMeshActor.h"
#include "RTMeshHandler.h"
#include "RealtimeMeshSimple.h"
#include "RTMeshActor.generated.h"



UCLASS()
class PROCEDURALGENERATION_API ARTMeshActor : public ARealtimeMeshActor
{
	GENERATED_BODY()

	public:
	ARTMeshActor();
	~ARTMeshActor();	
	virtual void BeginPlay() override;
	virtual void OnGenerateMesh_Implementation() override;

	void initComponents();
	void generateMesh();



	private:
	RTMeshHandler* meshHandler;
	URealtimeMeshSimple* rtMesh;

};
