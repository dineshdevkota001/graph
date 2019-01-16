#pragma once
#include<cmath>
#include<iostream>
class Transformation
{
	float def[4][4] = { 1,0,0,0,
						  0,1,0,0,
						  0,0,1,0,
						  0,0,0,1 };
public:
	float trans[4][4] = { 1,0,0,0,
						  0,1,0,0,
						  0,0,1,0,
						  0,0,0,1 };
	Transformation();
	void defaultize();
	void makeTraMatrix(float tx, float ty, float tz);
	void makeRotMatrix(float rx, float ry, float rz);
	void makescaleMatrix(float sx, float sy, float sz);
	~Transformation();
};

