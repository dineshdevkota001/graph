#include "Display.h"



Display::Display()
{}

int Display::create_window() {
	cout << "creating window" << endl;
	if (!glfwInit()) {
		cout << "GLFW NOT INITIATED!!!" << endl;
	}

	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_CONTEXT_REVISION, 0);

	window = glfwCreateWindow(width, height, "OpenGL Viewport", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	return 0;
	cout << "exited of creating window" << endl;
}

int Display::entrypoint()
{
	cout << "entrypoint function" << endl;

	Display::create_window();
	graphics.makeprogram();
	Display::refresh_window();
	Display::close_window();
	cout << "exiting entrypoint" << endl;

	return 0;
}

void Display::rotate() {
	int m = 0;
	for (int k = 0; k < (graphics.f.nov) / 5; k++)
	{
		for (int i = 0; i < 3; i++)
		{
			float sum = 0;
			for (int j = 0; j < 3; j++)
			{
				sum += t.trans[i][j] * graphics.f.vertices[m + j];
			}
			graphics.f.vertices[m + i] = sum;
		}
		m += 5;
	}
}

void Display::translate() {
	int m = 0;
	for (int k = 0; k < (graphics.f.nov) / 5; k++)
	{
		for (int i = 0; i < 3; i++)
		{
			graphics.f.vertices[m++] += t.trans[i][3];
		}
		m++;
		m++;
	}
}

void Display::scale() {
	int m = 0;
	for (int k = 0; k < (graphics.f.nov) / 5; k++)
	{
		for (int i = 0; i < 3; i++)
		{
			graphics.f.vertices[m++] *= t.trans[i][i];
		}
		m++;
		m++;
	}
}


void Display::refresh_window() {

	graphics.bindAll();
	cout << "Refresh loop" << endl;

	while (!glfwWindowShouldClose(window))
	{
		Display::processInput();
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		graphics.useprogram();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}


void Display::close_window() {
	cout << "closing window" << endl;

	graphics.deleteAll();
	glfwTerminate();
}


void Display::processInput()
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	}
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
		float x, y, z;
		cin >> x >> y >> z;
		t.makeRotMatrix(x, y, z);
		Display::rotate();
		graphics.bindAll();
	}
	if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS) {
		float x, y, z;
		cin >> x >> y >> z;
		t.makescaleMatrix(x, y, z);
		Display::scale();
		graphics.bindAll();
	}
	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS) {
		float x, y, z;
		cin >> x >> y >> z;
		t.makeTraMatrix(x, y, z);
		Display::translate();
		graphics.bindAll();
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		t.makeRotMatrix(0, 0, -0.1f);
		Display::rotate();
		graphics.bindAll();
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		t.makeRotMatrix(0, 0, 0.1f);
		Display::rotate();
		graphics.bindAll();
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		t.makeRotMatrix(0, 0.1f, 0);
		Display::rotate();
		graphics.bindAll();
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		t.makeRotMatrix(0, -0.1f, 0);
		Display::rotate();
		graphics.bindAll();
	}
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		t.makeRotMatrix(-0.1f, 0, 0);
		Display::rotate();
		graphics.bindAll();
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		t.makeRotMatrix(0.1f, 0, 0);
		Display::rotate();
		graphics.bindAll();
	}
	if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS) {
		t.makeTraMatrix(0, 0.005f, 0);
		Display::translate();
		graphics.bindAll();
	}
	if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS) {
		t.makeTraMatrix(0, -0.005f, 0);
		Display::translate();
		graphics.bindAll();
	}
	if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) {
		t.makeTraMatrix(0.005f, 0, 0);
		Display::translate();
		graphics.bindAll();
	}
	if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) {
		t.makeTraMatrix(-0.005f, 0, 0);
		Display::translate();
		graphics.bindAll();
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		graphics.f.imp_obj();
		graphics.bindAll();
	}
	if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS)
	{
		t.makescaleMatrix(1.003f, 1.003f, 1.003f);
		Display::scale();
		graphics.bindAll();
	}
	if (glfwGetKey(window, GLFW_KEY_MINUS) == GLFW_PRESS)
	{
		t.makescaleMatrix(0.997f, 0.997f, 0.997f);
		Display::scale();
		graphics.bindAll();
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	cout << "Viewport changed"<<width<<"X"<<height<< endl;
	glViewport(0, 0, width, height);
}

Display::~Display()
{
}
