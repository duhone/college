// object_orbit.h: interface for the object_orbit class.
//
//////////////////////////////////////////////////////////////////////
//NAME: Eric Duhon
//SSN:  453-97-8531

#if !defined OBJECT_ORBIT_H
#define OBJECT_ORBIT_H


#include "object.h"

class object_orbit : public object  
{
public:
	object_orbit();
	virtual ~object_orbit();
	virtual void set_wire(bool arg);
		/*Draw wireframe or not*/
	virtual void render();
		/*Draw the object*/
};

#endif // !defined(OBJECT_ORBIT_H)
