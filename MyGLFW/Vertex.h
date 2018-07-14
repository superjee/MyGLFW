#pragma once
#include "glm-master\glm\glm.hpp"
class Vertex
{
private:
	glm::vec3 pos;
	glm::vec3 color;
public:
	Vertex();
	Vertex(float x, float y, float z, float r, float g, float b);
	~Vertex();

	int test();
};

