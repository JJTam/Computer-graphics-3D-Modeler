#include "MarchingCube.h"

int MarchingCube::Polygonise(GRIDCELL grid, double isolevel, TRIANGLE* triangles)
{
        int i, num_triangle;
        int cubeindex;
        Vec3f vertlist[12];

        cubeindex = 0;
        if (grid.value[0] < isolevel) cubeindex |= 1;
        if (grid.value[1] < isolevel) cubeindex |= 2;
        if (grid.value[2] < isolevel) cubeindex |= 4;
        if (grid.value[3] < isolevel) cubeindex |= 8;
        if (grid.value[4] < isolevel) cubeindex |= 16;
        if (grid.value[5] < isolevel) cubeindex |= 32;
        if (grid.value[6] < isolevel) cubeindex |= 64;
        if (grid.value[7] < isolevel) cubeindex |= 128;

        /* Cube is entirely in/out of the surface */
        if (edgeTable[cubeindex] == 0)
            return(0);

        /* Find the vertices where the surface intersects the cube */
        if (edgeTable[cubeindex] & 1)
            vertlist[0] =
            VertexInterp(isolevel, grid.p[0], grid.p[1], grid.value[0], grid.value[1]);
        if (edgeTable[cubeindex] & 2)
            vertlist[1] =
            VertexInterp(isolevel, grid.p[1], grid.p[2], grid.value[1], grid.value[2]);
        if (edgeTable[cubeindex] & 4)
            vertlist[2] =
            VertexInterp(isolevel, grid.p[2], grid.p[3], grid.value[2], grid.value[3]);
        if (edgeTable[cubeindex] & 8)
            vertlist[3] =
            VertexInterp(isolevel, grid.p[3], grid.p[0], grid.value[3], grid.value[0]);
        if (edgeTable[cubeindex] & 16)
            vertlist[4] =
            VertexInterp(isolevel, grid.p[4], grid.p[5], grid.value[4], grid.value[5]);
        if (edgeTable[cubeindex] & 32)
            vertlist[5] =
            VertexInterp(isolevel, grid.p[5], grid.p[6], grid.value[5], grid.value[6]);
        if (edgeTable[cubeindex] & 64)
            vertlist[6] =
            VertexInterp(isolevel, grid.p[6], grid.p[7], grid.value[6], grid.value[7]);
        if (edgeTable[cubeindex] & 128)
            vertlist[7] =
            VertexInterp(isolevel, grid.p[7], grid.p[4], grid.value[7], grid.value[4]);
        if (edgeTable[cubeindex] & 256)
            vertlist[8] =
            VertexInterp(isolevel, grid.p[0], grid.p[4], grid.value[0], grid.value[4]);
        if (edgeTable[cubeindex] & 512)
            vertlist[9] =
            VertexInterp(isolevel, grid.p[1], grid.p[5], grid.value[1], grid.value[5]);
        if (edgeTable[cubeindex] & 1024)
            vertlist[10] =
            VertexInterp(isolevel, grid.p[2], grid.p[6], grid.value[2], grid.value[6]);
        if (edgeTable[cubeindex] & 2048)
            vertlist[11] =
            VertexInterp(isolevel, grid.p[3], grid.p[7], grid.value[3], grid.value[7]);

        /* Create the triangle */
        num_triangle = 0;
        for (i = 0;triTable[cubeindex][i] != -1;i += 3) {
            triangles[num_triangle].point[0] = vertlist[triTable[cubeindex][i]];
            triangles[num_triangle].point[1] = vertlist[triTable[cubeindex][i + 1]];
            triangles[num_triangle].point[2] = vertlist[triTable[cubeindex][i + 2]];
            num_triangle++;
        }

        return(num_triangle);
}

Vec3f MarchingCube::VertexInterp(float isolevel, Vec3f p1, Vec3f p2, float valp1, float valp2)
{
    double mu;
    Vec3f p;

    if (std::abs(isolevel - valp1) < 0.00001)
        return(p1);
    if (std::abs(isolevel - valp2) < 0.00001)
        return(p2);
    if (std::abs(valp1 - valp2) < 0.00001)
        return(p1);
    mu = (isolevel - valp1) / (valp2 - valp1);
    p[0] = p1[0] + mu * (p2[0] - p1[0]);
    p[1] = p1[1] + mu * (p2[1] - p1[1]);
    p[2] = p1[2] + mu * (p2[2] - p1[2]);

    return(p);
}
