#include "Fileman.h"

Fileman::Fileman()
{
	s = "test";
	Fileman::imp_obj();
}

Fileman::Fileman(string a):s(a) {}

void Fileman::imp_obj(){
	cout << "Opening File.." << endl;
	ifstream file;
	int i = 0, j = 0, k = 0, l = 0;
	file.open("Resources/"+s+".object");
	if (!file) {
		cout << "cannot open file" << endl;
		exit(1);
	}
	cout << "Importing Vertices and Textures .";
	float max = 0;
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
			vertices[i++] = x;
			if (fabs(x) > max) max = fabs(x);
			vertices[i++] = y;
			if (fabs(y) > fabs(max)) max = fabs(y);
			vertices[i++] = -z;
			if (fabs(z) > fabs(max)) max = fabs(z);
			i++;
			i++;

			continue;
		}
		else if (type == "vt") {
			float x, y;
			in >> x >> y;
			textures[j++] = x;
			textures[j++] = 1-y;
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

		l++;
		if (l == 100)
		{
			cout << ".";
			l = 0;
		}
	}
	cout << endl << "Calculating Optimals";
	nov = i;
	nof = k;
	l = 0;
	for (int m = 0; m < nov; m) {
		vertices[m++] /= max;
		vertices[m++] /= max;
		vertices[m++] /= max;
		m++;
		m++;
		l++;
		if (l == 16) {
			cout << ".";
		}
	}
	cout << endl;
	file.close();
}

void Fileman::deletemem()
{
	delete[] indices;
	delete[] textures;
	delete[] vertices;
}


Fileman::~Fileman()
{
}
