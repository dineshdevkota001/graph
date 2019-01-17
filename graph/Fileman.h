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
	//increase the no. of vertices as required

	float* vertices = new float[10000];
	float* vertice = new float[10000];
	float* textures = new float[10000];
	int* indices= new int[10000];
	int nov, nof, non, nom;

	Fileman();
	Fileman(string a);
	void imp_obj();
	~Fileman();
};

