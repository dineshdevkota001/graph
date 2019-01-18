#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"Fileman.h"

using namespace std;

class G_items
{
	const char *vertexShaderSource = "#version 130 core\n"
		"in vec3 aPos;\n"
		"in vec2 aTexCoord;\n"
		"out vec2 TexCoord;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x*(9-3*aPos.z)/16, aPos.y*(3-aPos.z)/3, aPos.z, 1.0);\n"
		"	TexCoord = aTexCoord;\n"
		"}\0";
	const char *fragmentShaderSource = "#version 130 core\n"
		"out vec4 FragColor;\n"
		"in vec2 TexCoord;\n"

		"uniform sampler2D ourTexture;\n"

		"void main()\n"
		"{\n"
		"   FragColor = texture(ourTexture, TexCoord);\n"
		"}\n\0";

	GLuint vertexShader, fragmentShader, shaderProgram;
	unsigned int VBO, VAO, EBO, texture;
public:
	Fileman file;

	G_items();

	void makeprogram();
	void bindTexture();
	void bindAll();
	void deleteAll();
	void useprogram();

	~G_items();
};

