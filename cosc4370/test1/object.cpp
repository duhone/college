// object.cpp: implementation of the object class.
//
//////////////////////////////////////////////////////////////////////

#include "object.h"
#include <string.h>
#include "gl\glut.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

object::object()
{
	vertexPos = 0;
	colorarray = 0;
}

object::~object()
{
	delete[] vertexPos;
	delete[] colorarray;
}


void object::setVertexArray(float *array, int size)
{
	if(vertexPos != 0)
		delete[] vertexPos;
	vertexPos = new float[size];
	memcpy(vertexPos,array,sizeof(float)*size);
	vertexsize = size;

}

void object::render()
{
	glVertexPointer(3,GL_FLOAT,0,vertexPos);
	glColorPointer(4,GL_FLOAT,0,colorarray);
	glDrawArrays(GL_TRIANGLES,0,vertexsize/3);
}

void object::setColorArray(float *array, int size)
{
	if(colorarray != 0)
		delete[] colorarray;
	colorarray = new float[size];
	memcpy(colorarray,array,sizeof(float)*size);
	colorsize = size;

}

