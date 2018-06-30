#include <iostream>
#include <GLFW\glfw3.h>

class Vec3 {
public :
	float x, y, z;
	Vec3(float _x, float _y, float _z) :x(_x), y(_y), z(_z) { }
};
class Trinagle {
public://private:
	Trinagle();
	Vec3 trans;
	Vec3 rot;
	Vec3 scale;
	float t;
	
//public:
	void draw()
	{
		glPushMatrix();
		glTranslatef(trans.x, trans.y, trans.z);
		glRotatef(t, rot.x, rot.y, rot.z);
		glScalef(scale.x, scale.y, scale.z);
		drawTrinagle();
		float size = 0.5f;
		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-size, size, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, size * 2, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(size, size, 0.0f);
		glEnd();
		glPopMatrix();
	}
};
void drawTrinagle() {
	float size = 0.5f;
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-size, size, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, size * 2, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(size, size, 0.0f);
	glEnd();
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

		Trinagle tri1;
		Trinagle tri2;





		//ÇÒ´·Ø¡ÍÂèÒ§¡èÍ¹ÊÅÑºBuffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	}
	glfwTerminate();

	getchar();
	return 0;
}