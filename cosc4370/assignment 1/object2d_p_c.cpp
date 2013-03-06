// object2d_p_c.cpp: implementation of the object2d_p_c class.
//
//////////////////////////////////////////////////////////////////////

#include "object2d_p_c.h"
#include "gl/glut.h"
#include<string.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

object2d_p_c::object2d_p_c()
		/*constructs a new 2d object. the object has no data*/
{
	vertexPos = 0;
	colorarray = 0;

}

object2d_p_c::~object2d_p_c()
		/*destroy object and release all memory*/
{
	delete[] vertexPos;
	delete[] colorarray;

}

void object2d_p_c::setVertexArray(float *array, int size)
		/*sets the vertexarray(position data). Parameter array is copied into the object. 
			size is the number of elements to copy*/
{
	if(vertexPos != 0)
		delete[] vertexPos;
	vertexPos = new float[size];
	memcpy(vertexPos,array,sizeof(float)*size);
	vertexsize = size;

}

void object2d_p_c::render()
		/*renders the 2d object using specifed position and color data.Do not call before 
			setting the vertexarray and the colorarray*/
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_INDEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_EDGE_FLAG_ARRAY);

	glVertexPointer(2,GL_FLOAT,0,vertexPos);
	glColorPointer(4,GL_FLOAT,0,colorarray);
	glDrawArrays(GL_TRIANGLES,0,vertexsize/2);
}

void object2d_p_c::setColorArray(float *array, int size)
		/*sets the values of the color for the 2d object. Parameter
			array is copied into the object.size is the number of elemnts in array*/
{
	if(colorarray != 0)
		delete[] colorarray;
	colorarray = new float[size];
	memcpy(colorarray,array,sizeof(float)*size);
	colorsize = size;

}

