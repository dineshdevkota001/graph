#include "Transformation.h"



Transformation::Transformation()
{
}

void Transformation::defaultize() {
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == j) trans[i][i] = 1;
			else trans[i][j] = 0;
		}
	}
}

void Transformation::makeTraMatrix(float tx, float ty, float tz) {
	Transformation::defaultize();
	trans[0][3] = tx;
	trans[1][3] = ty;
	trans[2][3] = tz;
}

void Transformation::makeRotMatrix(float rx, float ry, float rz) {
	Transformation::defaultize();
	float f = 3.14159265359 / 180.0f;
	rx *= f;
	ry *= f;
	rz *= f;
	trans[0][0] = cos(ry)*cos(rz);
	trans[0][1] = sin(rz)*cos(rx) - cos(rz)*sin(ry)*sin(rx);
	trans[0][2] = sin(rz)*sin(rx) + cos(rz)*sin(ry)*cos(rx);
	trans[1][0] = -sin(rz)*cos(ry);
	trans[1][1] = cos(rz)*cos(rx) + sin(rz)*sin(ry)*sin(rx);
	trans[1][2] = cos(rz)*sin(rx) - sin(rz)*sin(ry)*cos(rx);
	trans[2][0] = -sin(ry);
	trans[2][1] = -sin(rx)*cos(ry);
	trans[2][2] = cos(rx)*cos(ry);
}

void Transformation::makescaleMatrix(float sx, float sy, float sz) {
	Transformation::defaultize();
	trans[0][0] = sx;
	trans[1][1] = sy;
	trans[2][2] = sz;
}

Transformation::~Transformation()
{
}
