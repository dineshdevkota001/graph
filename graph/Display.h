#pragma once
#include"G_items.h"
#include "Transformation.h"

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class Display
{
private:
	const int width = 1366, height = 768;
	G_items graphics;
	GLFWwindow* window;
	Transformation t;
public:
	Display();
	void processInput();
	void close_window();
	void refresh_window();
	int create_window();
	int entrypoint();
	
	void rotate();
	void translate();
	void scale();
	~Display();
};