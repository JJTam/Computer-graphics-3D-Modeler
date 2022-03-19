// reference: https://www.aiwalls.com/android%E8%BB%9F%E9%AB%94%E9%96%8B%E7%99%BC%E6%95%99%E5%AD%B8/03/25799.html

#pragma once
#include "MarchingCube.h"
#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>

#include "modelerglobals.h"
#include "bitmap.h" 

class MetaBall
{
public:
	float threshold = 1.0;
	float gridSize = 0.25;
	float radius = 1;
	float distanceDifference;

	float xLength = 4.0;
	float yLength = 12.0;
	float zLength = 4.0;
	
	Vec3f ball1;
	Vec3f ball2;



public:
	MetaBall(float distanceDifference);
	float calculateEnergy(float radius, Vec3f point, Vec3f centerOfSphere);
	float differenceOfTwoBall(Vec3f ball1, Vec3f ball2);
	void drawMetaBall();
	GRIDCELL generateGridCell(Vec3f vertex);

	Vec3f crossProduct(Vec3f vector1, Vec3f vector2);
	Vec3f calculateNormalVector(Vec3f vector1, Vec3f vector2, Vec3f vector3);
};

