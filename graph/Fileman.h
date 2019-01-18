#pragma once
#include<fstream>
#include<sstream>
#include<iostream>
#include<string>


using namespace std;

class Fileman
{
	string s;
public:

	float* vertices = new float[8400];
	float* textures = new float[5600];
	int* indices= new int[7800];
	int nov, nof;

	Fileman();
	Fileman(string a);
	
	void imp_obj();
	void deletemem();
	~Fileman();
};

