// object_orbit.cpp: implementation of the object_orbit class.
//
//////////////////////////////////////////////////////////////////////
//NAME: Eric Duhon
//SSN:  453-97-8531

#include "object_orbit.h"
#include<math.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

object_orbit::object_orbit()
{

}

object_orbit::~object_orbit()
{

}


	
void object_orbit::render()
/*Render the orbit line using 100 segments if it is enabled*/
{
	if(enabled)
	{
		glBegin(GL_LINE_LOOP);
		int count = 0;
		for(count = 0;count < 100;count++)
			glVertex3f(cos(6.28/100 * count),0,sin(6.28/100 * count));

		glEnd();
	}

}

void object_orbit::set_wire(bool arg)
/*wireframe doesnt apply to this object so do nothing*/
{

}
