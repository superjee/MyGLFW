#pragma once
#include "Vec3.hpp"
#include <iostream>
#include <GLFW\glfw3.h>

class Triangle
{
public:
	Triangle();
	~Triangle();

//private:
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
};

