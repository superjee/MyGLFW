#include "App.h"
#include <iostream>
#include <functional>

#include "glm-master\glm\gtc\matrix_transform.hpp"
#include "glm-master\glm\gtc\type_ptr.hpp"

using namespace std;

void linkCheck(GLuint ID) {
	GLint linkStatus, validateStatus;
	glGetProgramiv(ID, GL_LINK_STATUS, &linkStatus);

	if (linkStatus == GL_FALSE) {
		cout << "Shader Linking FAILED" << endl;
		GLchar messages[256];
		glGetProgramInfoLog(ID, sizeof(messages), 0, &messages[0]);
		cout << messages;
	}

	glValidateProgram(ID);
	glGetProgramiv(ID, GL_VALIDATE_STATUS, &validateStatus);

	cout << "Link: " << linkStatus << "  Validate: " << validateStatus << endl;
	if (linkStatus == GL_FALSE) {
		cout << "Shader Validation FAILED" << endl;
		GLchar messages[256];
		glGetProgramInfoLog(ID, sizeof(messages), 0, &messages[0]);
		cout << messages;
	}
}

App::App()
{
}

App::~App()
{
	glfwTerminate();
}

void App::init(int WIDTH,int HEIGHT,const std::string& tittle)
{
	this->width = WIDTH;
	this->height = HEIGHT;

	/*initialize the glfw system*/
	if (!glfwInit())
	{
		glfwTerminate();
		return;
	}
	window = glfwCreateWindow(WIDTH, HEIGHT, tittle.c_str(), /*glfwGetPrimaryMonitor()*/ nullptr, nullptr/*window*/);
	if (!window)
	{
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);
	//glfwSetKeyCallback(window, key_callback);
	glfwSetWindowUserPointer(window, this);
	glfwSetKeyCallback(window, key_callback_static);
	/**/
	GLenum result = glewInit();
	if (result != GLEW_OK)
	{
		std::cout << "GLEW error:" <<
			glewGetErrorString(result) << std::endl;
		getchar();
		return;
	}

	const auto glVersion = glGetString(GL_VERSION);
	std::cout << "GL version : " << glVersion << std::endl;

	const GLubyte* shaderVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
	std::cout << "GLSL version : " << shaderVersion << std::endl;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_CONSTANT_ALPHA);

	initShaderProgram();
	initMesh();

}

void App::initMesh()
{
	// In the CPU RAM
	vertices.push_back(Vertex(-0.6f, -0.4f, 0.0f, 1.0f, 0.0f, 0.0f));
	vertices.push_back(Vertex(0.6f, -0.4f, 0.0f, 0.0f, 0.0f, 1.0f));
	vertices.push_back(Vertex(0.0f, 0.6f, 0.0f, 0.0f, 1.0f, 0.0f));
	vertices.push_back(Vertex(0.0f, -0.6f, 0.0f, 0.0f, 1.0f, 0.0f));
	
	//Move To GPU RAM(VRAM)
	//GLuint vertexArrayID;
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);
	GLuint bufferID;
	glGenBuffers(1, &bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferID);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex),
		vertices.data(), GL_STATIC_DRAW);

	mvp_location = glGetUniformLocation(programID, "MVP");
	GLint vpos_location = glGetAttribLocation(programID, "vPos");
	GLint vcolor_location = glGetAttribLocation(programID, "vCol");

	glEnableVertexAttribArray(vpos_location);
	glEnableVertexAttribArray(vcolor_location);
	glVertexAttribPointer(vpos_location, 3, GL_FLOAT,
		GL_FALSE, sizeof(Vertex), (void*)0);
	glVertexAttribPointer(vcolor_location, 3, GL_FLOAT, GL_FALSE,
		sizeof(Vertex), (void*)(sizeof(float)*3));
}

void App::initShaderProgram()
{
	//1. write  Two shader codes
	static const char* vertexShaderCode =
		"uniform mat4 MVP; \n"
		"attribute vec3 vPos; \n"
		"attribute vec3 vCol; \n"
		"varying vec3 color; \n"
		"void main() \n "
		"{ \n"
		"   gl_Position = MVP * vec4(vPos, 1.0); \n"
		"   color = vCol; \n"
		"} \n";

	static const char* fragmentShaderCode =
		"varying vec3 color; \n"
		"void main() \n"
		"{ \n"
		"    gl_FragColor = vec4(color, 1.0); \n"
		"} \n";

	//2. load the shader codes
	//GLuint 
	programID = glCreateProgram();
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderCode, NULL);
	glShaderSource(fragmentShader, 1, &fragmentShaderCode, NULL);
	//3. compile the codes
	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);
	//3.1 Check the compile
		//https://d.pr/D63ZbS
	//4. attach the codes
	glAttachShader(programID,vertexShader);
	glAttachShader(programID,fragmentShader);
	//5. link the codes
	glLinkProgram(programID);


	linkCheck(programID);

	//6. use the shader program

}

void App::key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_E && action == GLFW_PRESS)
	{
		std::cout << "I pressed E" << std::endl;
	}
}

void App::key_callback_static(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	App* that = static_cast<App*>(glfwGetWindowUserPointer(window));
	that->key_callback(window, key, scancode, action, mods);
}

void App::Start()
{
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//glClear(GL_COLOR_BUFFER_BIT); // render color
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //glClearColor(0, 1, 0, 1.0f); //change color
		//OpenGl immediate mode (depricated)

		float ratio = width / static_cast<float>(height);
		glViewport(0, 0, width, height);

		//initalize transformation
		const glm::vec3 axis(0, 0, 1);
		glm::vec3 trs(0, 0, 0);
		glm::vec3 vscale(1, 1, 1);

		//create a model matrix
		glm::mat4 translation = glm::translate(glm::mat4(1.0f), trs);
		//glm::mat4 rotation = glm::translate(glm::mat4(1.0f), (glm::mediump_float));

		glm::mat4x4 m = glm::mat4(1.0);
		glm::mat4x4 vp = glm::ortho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		glm::mat4x4 mvp = m * vp;

		glUseProgram(programID);
		glUniformMatrix4fv(mvp_location, 1, GL_FALSE, glm::value_ptr(mvp));

		glBindVertexArray(vertexArrayID);

		glDrawArrays(GL_LINES,0,4);//GL_TRIANGLES

		//«“¥∑ÿ°Õ¬Ë“ß°ËÕπ ≈—∫Buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	}
	//glfwTerminate();
}
