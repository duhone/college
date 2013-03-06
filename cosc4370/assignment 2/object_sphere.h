// object_sphere.h: interface for the object_sphere class.
//
//////////////////////////////////////////////////////////////////////
//NAME: Eric Duhon
//SSN:  453-97-8531

#if !defined OBJECT_SPHERE_H
#define OBJECT_SPHERE_H


#include "object.h"
#include "gl\glut.h"

class object_sphere : public object  
{
public:
	virtual void set_wire(bool arg);
		/*Draw wireframe or not*/
	object_sphere();
	virtual ~object_sphere();
	virtual void render();
		/*Draw the object*/

private:
	bool wire;
};

#endif // !defined(OBJECT_SPHERE_H)
