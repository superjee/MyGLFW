#include <iostream>
#include <glew.h> //Must Top On glfw3
#include <GLFW\glfw3.h>
#include "Vec3.hpp"
#include "Triangle.hpp"   
#include <crtdbg.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "glm-master\glm\vec2.hpp"
#include "App.h"


int WIDTH = 800;//192;
int HEIGHT = 600;//108;
int SetNum = 1;
class RainDrop {
private :
	float x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float dummyX = rand() % 2;
	float y = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float dummyY = rand() % 3 + 1;
	float length = 0.05f;
	float yspeed = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX))/70;
public:
	RainDrop() {
		if (dummyX == 1)
		{
			x *= -1;
		}
		y += dummyY;
	}

	void fall() {
		y = y - yspeed;

		if (y < -1) {
			yspeed = (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) / 70;
			y = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			y += dummyY;
			x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			dummyX = rand() % 2;
			if (dummyX == 1)
			{
				x *= -1;
			}
		}
	}

	void show(int num) {
		if (num == 1)
		{
			glLineWidth(0.55f * (yspeed * 500));
			glBegin(GL_LINES);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(x, y, 0.0f);
			glVertex3f(x, y - (length*yspeed * 250), 0);
			glEnd();
		}
		else if (num == 2)
		{
			glPushMatrix();
			glTranslatef(x, y - (length*yspeed * 250), 0);
			glScalef(0.55f * (yspeed * 500), 0.55f * (yspeed * 500), 0);
			float size = 0.1f;
			glBegin(GL_TRIANGLES);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(-size / 2, size, 0.0f);
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(0.0f, -(size) / 2, 0.0f);
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(size / 2, size, 0.0f);
			glEnd();
			glPopMatrix();
		}
	}
};

bool isClose = false;
/*void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_E && action == GLFW_PRESS)
	{
		std::cout << "I pressed E" << std::endl;
		isClose = true;
	}
	if (key == GLFW_KEY_1 && action == GLFW_PRESS)
	{
		std::cout << "1" << std::endl;
		SetNum = 1;
	}
	if (key == GLFW_KEY_2 && action == GLFW_PRESS)
	{
		std::cout << "2" << std::endl;
		SetNum = 2;
	}
}*/

/*glm::vec2 v;
v.x = 5;
v.y = 10;
std::cout << v.y << std::endl;*/

/*int MAX_RAIN = 1000;
RainDrop *rain = new RainDrop[MAX_RAIN];

float r = 0.0f;
float g = 0.0f;
float b = 0.0f;
bool color_up = true;*/

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	srand(time(NULL));

	App app;
	app.init(WIDTH, HEIGHT, "MyApp");
	app.Start();

	/*game loop*/
	/*while (!glfwWindowShouldClose(window) && isClose == false)
	{
		glClear(GL_COLOR_BUFFER_BIT); // render color
		if (color_up)
		{
			r += 0.0001;
			g += 0.00015;
			b += 0.0002;
			if (r > 1)
			{
				r = 1;
			}
			if (g > 1)
			{
				g = 1;
			}
			if (b > 1)
			{
				b = 1;
			}
			if (r == 1 && g == 1 && b == 1)
			{
				color_up = false;
			}
		}
		else
		{
			r -= 0.0001;
			g -= 0.0002;
			b -= 0.0003;
			if (r < 0)
			{
				r = 0;
			}
			if (g < 0)
			{
				g = 0;
			}
			if (b < 0)
			{
				b = 0;
			}
			if (r == 0 && g == 0 && b == 0)
			{
				color_up = true;
			}
		}

		glClearColor(r, g, b, 1.0f); //change color
		//OpenGl immediate mode (depricated)
		for (int i = 0; i < MAX_RAIN; i++)
		{
			rain[i].fall();
			rain[i].show(SetNum);
		}

		//ÇÒ´·Ø¡ÍÂèÒ§¡èÍ¹ÊÅÑºBuffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	}
	glfwTerminate();
	delete []rain;*/
	getchar();
	return 0;
}
