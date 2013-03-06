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
		/*constructer. sets usage to 0, so make sure to call addref to increment usage if needed*/
{
	ref = 0;
}

object::~object()
		/*destructor*/
{
}



void object::Release()
		/*Lets the object know that a pointer to this object is no longer needed. If there
			are no more pointers to this object the object will selfdestruct.*/
{
	ref--;
	if(ref == 0)
		delete this;

}

void object::addRef()
	/*Lets the object know that another pointer has been assigned the adress of this
			object*/
{
	ref++;
}
