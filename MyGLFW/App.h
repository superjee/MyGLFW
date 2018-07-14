#pragma once
#include <iostream>
#include <string>
#include <glew.h> //Must Top On glfw3
#include <GLFW\glfw3.h>

#include <vector>

#include "Vertex.h"
class App final
{
private:
	
	GLFWwindow *window = nullptr;
	std::vector<Vertex> vertices;
	
	GLuint programID;
	GLuint vertexArrayID;
	GLint mvp_location;

	int width;
	int height;
public:
	App();
	~App();
	void Start();
	void init(int WIDTH, int HEIGHT, const std::string& tittle);
	void initMesh();
	void initShaderProgram();

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void key_callback_static(GLFWwindow* window, int key, int scancode, int action, int mods);
};

