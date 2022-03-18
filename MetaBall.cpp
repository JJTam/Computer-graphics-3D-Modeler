#include "MetaBall.h"

MetaBall::MetaBall(float distanceDifference)
	: ball1(2, 4 - distanceDifference, 2), ball2(2, 4 + distanceDifference, 2)
{
}

float MetaBall::calculateEnergy(float radius, Vec3f point, Vec3f centerOfSphere)
{
	float denominator = pow((point[0] - centerOfSphere[0]), 2) + pow((point[1] - centerOfSphere[1]), 2) + pow((point[2] - centerOfSphere[2]), 2);
	return pow(radius, 2) / denominator;
}


float MetaBall::differenceOfTwoBall(Vec3f ball1, Vec3f ball2)
{
	return sqrt(abs(ball1[0] - ball2[0]) + abs(ball1[1] - ball2[1]) + abs(ball1[2] - ball2[2]));
}

void MetaBall::drawMetaBall()
{
	if (differenceOfTwoBall(ball1, ball2) <= 2 * radius)
	{
		TRIANGLE triangles[5];
		int num_triangle = 0;
		for (float x = 0; x < xLength; x += gridSize)
		{
			for (float y = 0; y < yLength; y += gridSize)
			{
				for (float z = 0; z < zLength; z += gridSize)
				{
					Vec3f currentVertex(x, y, z);
					GRIDCELL gridcell = generateGridCell(currentVertex);
					num_triangle = MarchingCube::Polygonise(gridcell, 1, triangles);
					for (int i = 0; i < num_triangle; i++)
					{
						Vec3f normalVector = calculateNormalVector(triangles[i].point[0], triangles[i].point[1], triangles[i].point[2]);
						glBegin(GL_TRIANGLES);
							glNormal3f(normalVector[0], normalVector[1], normalVector[2]);
							glVertex3f(triangles[i].point[0][0], triangles[i].point[0][1], triangles[i].point[0][2]);
							glVertex3f(triangles[i].point[1][0], triangles[i].point[1][1], triangles[i].point[1][2]);
							glVertex3f(triangles[i].point[2][0], triangles[i].point[2][1], triangles[i].point[2][2]);
						glEnd();
					}
				}
			}
		}
	}
}

GRIDCELL MetaBall::generateGridCell(Vec3f vertex)
{
	GRIDCELL gridCell;

	gridCell.p[0] = Vec3f(vertex[0]				, vertex[1]				, vertex[2]				);
	gridCell.p[1] = Vec3f(vertex[0] + gridSize	, vertex[1]				, vertex[2]				);
	gridCell.p[2] = Vec3f(vertex[0] + gridSize	, vertex[1]				, vertex[2] + gridSize	);
	gridCell.p[3] = Vec3f(vertex[0]				, vertex[1]				, vertex[2] + gridSize	);
	gridCell.p[4] = Vec3f(vertex[0]				, vertex[1] + gridSize	, vertex[2]				);
	gridCell.p[5] = Vec3f(vertex[0] + gridSize	, vertex[1] + gridSize	, vertex[2]				);
	gridCell.p[6] = Vec3f(vertex[0] + gridSize	, vertex[1] + gridSize	, vertex[2] + gridSize	);
	gridCell.p[7] = Vec3f(vertex[0]				, vertex[1] + gridSize	, vertex[2] + gridSize	);

	for (int i = 0; i < 8; i++)
	{
		gridCell.value[i] = calculateEnergy(radius, gridCell.p[i], ball1) + calculateEnergy(radius, gridCell.p[i], ball2);
	}

	return gridCell;
}

Vec3f MetaBall::crossProduct(Vec3f vector1, Vec3f vector2)
{
	Vec3f resultVector(		vector1[0] * vector2[2] - vector1[2] * vector2[1],
						  -(vector1[0] * vector2[2] - vector1[2] * vector2[0]),
							vector1[0] * vector2[1] - vector1[1] * vector2[0]	);

	return resultVector;
}

Vec3f MetaBall::calculateNormalVector(Vec3f vector1, Vec3f vector2, Vec3f vector3)
{
	Vec3f x(vector1[0] - vector2[0], vector1[1] - vector2[0], vector1[2] - vector2[2]);
	Vec3f y(vector2[0] - vector3[0], vector2[1] - vector3[0], vector2[2] - vector3[2]);

	Vec3f result = crossProduct(x, y);
	result.normalize();

	return result;
}

