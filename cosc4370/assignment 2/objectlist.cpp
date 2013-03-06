// objectlist.cpp: implementation of the objectlist class.
//
//////////////////////////////////////////////////////////////////////
//NAME: Eric Duhon
//SSN:  453-97-8531

#include "objectlist.h"
#include "gl/glut.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

objectlist::objectlist()
		/*constructs a new empty list*/
{
	position = -20;
	twist = 0;
	look_updn = 10;
	look_ltrt = 0;
	view_scale = 0.1;

}

objectlist::~objectlist()
		/*destroys the list releasing all objects in the list*/
{
	object* temp;
	scalevector* temps;
	transvector* tempt;
	rotatevector* tempr;
	colorvector* tempc;
	for(int count = 0;count < list.size();count++)
	{
		temps = scalelist[count];
		delete temps;

		tempt = translist[count];
		delete tempt;

		tempr = rotatelist[count];
		delete tempr;
		
		tempc = colorlist[count];
		delete tempc;

		temp = list[count];
		temp->Release();
	}
}

void objectlist::addobject(object* newobj)
		/*adds an object to the list*/
{
	scalevector* temps;
	transvector* tempt;
	rotatevector* tempr;
	colorvector* tempc;
	temps = new scalevector();
	tempt = new transvector();
	tempr = new rotatevector();
	tempc = new colorvector();
	scalelist.push_back(temps);
	translist.push_back(tempt);
	rotatelist.push_back(tempr);
	colorlist.push_back(tempc);

	newobj->addRef();
	list.push_back(newobj);


}

void objectlist::renderlist()
		/*render all the objects in the list*/
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

//viewing transform
	glTranslatef(0,0,position);
	glRotatef(twist,0,0,1);
	glRotatef(look_updn,1,0,0);
	glRotatef(look_ltrt,0,1,0);
	glScalef(view_scale,view_scale,view_scale);

	object* temp;
	scalevector* temps;
	transvector* tempt;
	rotatevector* tempr;
	colorvector* tempc;
//save viewing transform on stack
	glPushMatrix();
	for(int count = 0;count < list.size();count++)
	{
		glPopMatrix();
		glPushMatrix();
		temps = scalelist[count];
		tempt = translist[count];
		tempr = rotatelist[count];
		tempc = colorlist[count];
//transform object
		glRotatef(tempr->x,1,0,0);
		glRotatef(tempr->y,0,1,0);
		glRotatef(tempr->z,0,0,1);
		glTranslatef(tempt->x,tempt->y,tempt->z);
		glScalef(temps->x,temps->y,temps->y);
//set color for this object
		glColor4f(tempc->r,tempc->g,tempc->b,tempc->a);

		temp = list[count];
		temp->render();
	}
	glPopMatrix();


}

void objectlist::scaleobj(int index, float x, float y, float z)
		/*scale the object at position index using the passed values*/
{
	scalevector* temps;
	temps = scalelist[index];
	temps->x = x;
	temps->y = y;
	temps->z = z;

}

void objectlist::rotateobj(int index, float x, float y, float z)
		/*rotate the object at position index using the passed values*/
{
	rotatevector* temps;
	temps = rotatelist[index];
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

void objectlist::setcolor(int index, float r, float g, float b,float a)
		/*set the color of the object at position index using the passed values*/
{
	colorvector* temps;
	temps = colorlist[index];
	temps->r = r;
	temps->g = g;
	temps->b = b;
	temps->a = a;

}

void objectlist::setwire(bool arg)
	/*set wireframe or not for all objects*/
{
	object* temp;
	for(int count = 0;count < list.size();count++)
	{
		
		temp = list[count];
		temp->set_wire(arg);
	}

}

void objectlist::move_view_pos(float arg)
	/*move the view position*/
{
	position += arg;
}

void objectlist::view_updn(float arg)
	/*rotate the view angle, x axis*/
{
	look_updn += arg;
}

void objectlist::view_ltrt(float arg)
	/*rotate the view angle, y axis*/
{
	look_ltrt += arg;
}

void objectlist::set_view_scale(float arg)
	/*scale the view transform*/
{
	view_scale = arg;
}

void objectlist::enable_object(int index, bool enable)
	/*enable or disable the object specified by index*/
{
	object* temp;
	temp = list[index];
	temp->enable_object(enable);
}

void objectlist::view_twist(float arg)
	/*rotate the view angle, z axis*/
{
	twist += arg;
}

void objectlist::reset_view()
	/*reset the view transform to default values*/
{
	position = -20;
	twist = 0;
	look_updn = 10;
	look_ltrt = 0;
	view_scale = 0.1;

}
