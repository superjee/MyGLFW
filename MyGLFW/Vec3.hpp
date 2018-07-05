#pragma once
class Vec3
{
public:
	Vec3();
	~Vec3();
	float x, y, z;
	Vec3(float _x, float _y, float _z) :x(_x), y(_y), z(_z) { }
};
