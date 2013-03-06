// objectlist.cpp: implementation of the objectlist class.
//
//////////////////////////////////////////////////////////////////////

#include "objectlist.h"
#include "gl/glut.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

objectlist::objectlist()
		/*constructs a new empty list*/
{

}

objectlist::~objectlist()
		/*destroys the list releasing all objects in the list*/
{
	object* temp;
	scalevector* temps;
	transvector* tempt;
	for(int count = 0;count < list.size();count++)
	{
		temps = scalelist[count];
		delete temps;

		tempt = translist[count];
		delete tempt;

		temp = list[count];
		temp->Release();
	}
}

void objectlist::addobject(object* newobj)
		/*adds an object to the list*/
{
	scalevector* temps;
	transvector* tempt;
	temps = new scalevector();
	tempt = new transvector();
	scalelist.push_back(temps);
	translist.push_back(tempt);

	newobj->addRef();
	list.push_back(newobj);


}

void objectlist::renderlist()
		/*render all the objects in the list*/
{
	glMatrixMode(GL_MODELVIEW);
	object* temp;
	scalevector* temps;
	transvector* tempt;
	for(int count = 0;count < list.size();count++)
	{
		temps = scalelist[count];
		tempt = translist[count];
		glLoadIdentity();
		glScalef(temps->x,temps->y,temps->y);
		glTranslatef(tempt->x,tempt->y,tempt->z);
	
		temp = list[count];
		temp->render();
	}

}

void objectlist::scaleobj(int index, float x, float y, float z)
		/*scale the object at position indes using the passed values*/
{
	scalevector* temps;
	temps = scalelist[index];
	temps->x = x;
	temps->y = y;
	temps->z = z;

}

void objectlist::transobj(int index, float x, float y, float z)
		/*translate the object held at position index using the passed values*/
{
	transvector* tempt;
	tempt = translist[index];
	tempt->x = x;
	tempt->y = y;
	tempt->z = z;

}
