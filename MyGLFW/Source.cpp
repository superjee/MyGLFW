#include <iostream>
#include <GLFW\glfw3.h>
#include "Vec3.hpp"
#include "Triangle.hpp"


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_E && action == GLFW_PRESS)
		std::cout << "I pressed E" << std::endl;
}

int main()
{
	std::cout << "hello";
	GLFWwindow *window = nullptr;

	/*initialize the glfw system*/
	if (!glfwInit())
	{
		glfwTerminate();
		return -1;
	}
	window = glfwCreateWindow(1280, 960, "My Game", nullptr, window);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);

	float size = 0.5f;
	float t1 = 0.0f;
	float t2 = 0.0f;
	/*game loop*/
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT); // render color
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f); //change color

		//OpenGl immediate mode (depricated)
		t1 += 0.5f;
		t2 += 0.5f;
		/*glPushMatrix();
			glTranslatef(0.5f, 0, 0);
			glRotatef(t2, 0, 1, 0);
			glScalef(0.5f, 0.5f, 0.5f);
			drawTrinagle();
		glPopMatrix();

		glPushMatrix();
		glRotatef(t1, 1, 0, 0);
		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-size, 0.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, size, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(size, 0.0f, 0.0f);
		glEnd();
		glPopMatrix();


		glPushMatrix();
		glRotatef(t1, 0, 0, 1);
		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-size, -size, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, size- size, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(size, -size, 0.0f);
		glEnd();
		glPopMatrix();*/

		Triangle tri1;
		Triangle tri2;

		tri1.trans = Vec3(0.5f, 0, 0);
		tri1.rot = Vec3(0, 1, 0);
		tri1.scale = Vec3(0.5f, 0.5f, 0.5f);
		tri1.t = t2;
		tri1.draw();



		//ÇÒ´·Ø¡ÍÂèÒ§¡èÍ¹ÊÅÑºBuffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	}
	glfwTerminate();

	getchar();
	return 0;
}
