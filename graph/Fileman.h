#pragma once
#include<fstream>
#include<sstream>
#include<iostream>
#include<string>


using namespace std;

struct material {
	///defines a material name and other variables i dont know
	string name = "noname";
	int Ns = 1;
	float Ka[3] = { 0,0,0 };
	float Kd[3] = { 0,0,0 };
	float Ks[3] = { 0,0,0 };
	float Ke[3] = { 0,0,0 };
	int d = 1;
	int illum = 1;
};

class Fileman
{
	string s;
public:
	//increase the no. of vertices as required

	float* vertices = new float[60000];
	float* textures = new float[60000];
	int* indices= new int[30000];
	material* mat = new material[20];
	int nov, nof, non, nom;

	Fileman();
	Fileman(string a);
	///import object;
	void imp_obj();
	void imp_mtl();
	~Fileman();
};

