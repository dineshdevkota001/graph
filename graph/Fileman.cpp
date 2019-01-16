#include "Fileman.h"



Fileman::Fileman()
{
	s = "test";
	Fileman::imp_obj();
}

Fileman::Fileman(string a):s(a) {}

void Fileman::imp_obj(){
	ifstream file;
	int i = 0, j = 0, k = 0;
	file.open(s+".obj");
	if (!file) {
		cout << "cannot open file" << endl;
		exit(1);
	}
	float max = 5;
	for (string line; getline(file, line); )
	{
		istringstream in(line);
		string type;
		in >> type;
		if (type=="blender"){}
		else if (type == "v")  
		{
			float x, y, z;
			in >> x >> y >> z;
			vertices[i++] = -x;
			if (fabs(x) > max) max = fabs(x);
			vertices[i++] = y;
			if (fabs(y) > fabs(max)) max = fabs(y);
			vertices[i++] = z;
			if (fabs(z) > fabs(max)) max = fabs(z);
			i++;
			i++;

			continue;
		}
		else if (type == "vt") {
			float x, y;
			in >> x >> y;
			textures[j++] = x;
			textures[j++] = y;
			continue;
		}
		else if (type == "f") {
			int x, a, b;
			char l;
			for (int i = 0; i < 3; i++) {
				in >> x >> l >> a >> l >> b;
				indices[k++] = --x;
				a--;
				vertices[(5*x)+3] = textures[2*a];
				vertices[(5*x)+4] = textures[2*a + 1];
			}
			continue;
		}

	}
	nov = i;
	non = j;
	nof = k;
	for (int m = 0; m < nov; m) {
		vertices[m++] /= max;
		vertices[m++] /= max;
		vertices[m++] /= max;
		m++;
		m++;
	}
	file.close();
}

void Fileman::imp_mtl(){

	ifstream file;
	int i = 0;
	file.open(s + ".mtl");
	if (!file) {
		cout << "cannot open file" << endl;
		exit(1);
	}

	for (string line; getline(file, line); )
	{
		istringstream in(line);
		string type;
		in >> type;
		if (type == "newmtl") {
			string name;
			in >> name;
			mat[i].name = name;
		}
		else if (type == "Ns") {
			int a;
			in >> a;
			mat[i].Ns = a;
		}
		else if (type == "Ka") {
			float x, y, z;
			in >> x >> y >> z;
			mat[i].Ka[0] = x;
			mat[i].Ka[1] = y;
			mat[i].Ka[2] = z;
		}
		else if (type == "Kd") {
			float x, y, z;
			in >> x >> y >> z;
			mat[i].Kd[0] = x;
			mat[i].Kd[1] = y;
			mat[i].Kd[2] = z;
		}
		else if (type == "Ks") {
			float x, y, z;
			in >> x >> y >> z;
			mat[i].Ks[0] = x;
			mat[i].Ks[1] = y;
			mat[i].Ks[2] = z;
		}
		else if (type == "Ke") {
			float x, y, z;
			in >> x >> y >> z;
			mat[i].Ke[0] = x;
			mat[i].Ke[1] = y;
			mat[i].Ke[2] = z;
		}
		else if (type == "d") {
			int a;
			in >> a;
			mat[i].d = a;
		}
		else if (type == "illum") {
			int a;
			in >> a;
			mat[i].illum = a;
			i++;
		}

	}
	file.close();
}


Fileman::~Fileman()
{
}
