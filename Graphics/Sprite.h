#pragma once
#include <GL\glew.h>

class Sprite
{
public:
	Sprite();
	~Sprite();

	void init(float x, float y, float w, float h);

	void draw();

private:
	float _x;
	float _y;
	float _width;
	float _height;
	GLuint _vboID;
};

