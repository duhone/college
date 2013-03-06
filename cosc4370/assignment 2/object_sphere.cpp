// object_sphere.cpp: implementation of the object_sphere class.
//
//////////////////////////////////////////////////////////////////////
//NAME: Eric Duhon
//SSN:  453-97-8531

#include "object_sphere.h"
#include "object.h"
#include <string.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

object_sphere::object_sphere()
{
	wire = false;
}

object_sphere::~object_sphere()
{

}

void object_sphere::render()
/*render the sphere using glut*/
{
	if(wire)
		glutWireSphere(1,20,20);
	else
		glutSolidSphere(1,20,20);
}



void object_sphere::set_wire(bool arg)
/*draw solid or wireframe*/
{
	wire = arg;
}
