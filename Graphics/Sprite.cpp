#include "Sprite.h"

Sprite::Sprite()
{
	_vboID = 0;
}


Sprite::~Sprite()
{
	if (_vboID != 0)
	{
		glDeleteBuffers(1, &_vboID);
	}
}


void Sprite::init(float x, float y, float w, float h)
{
	_x = x;
	_y = y;
	_width = w;
	_height = h;

	if (_vboID == 0)
	{
		glGenBuffers(1, &_vboID);
	}

	float vertexData[12];

	// one triangle
	vertexData[0] = x + w;
	vertexData[1] = y + h;
	
	vertexData[2] = x;
	vertexData[3] = y + w;

	vertexData[4] = x;
	vertexData[5] = y;

	//second triangle
	vertexData[6] = x;
	vertexData[7] = y;

	vertexData[8] = x + w;
	vertexData[9] = y;

	vertexData[10] = x + w;
	vertexData[11] = y + h;

	glBindBuffer(GL_ARRAY_BUFFER, _vboID);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, _vboID);

	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}