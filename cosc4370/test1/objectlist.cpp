// objectlist.cpp: implementation of the objectlist class.
//
//////////////////////////////////////////////////////////////////////

#include "objectlist.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

objectlist::objectlist()
{

}

objectlist::~objectlist()
{
	object* temp;
	for(int count = 0;count < list.size();count++)
	{
		temp = list[count];
		delete temp;
	}
}

void objectlist::addobject(float *posdata,int possize,float *colordata,int colsize)
{
	object* temp;
	temp = new object();
	temp->setVertexArray(posdata,possize);
	temp->setColorArray(colordata,colsize);

	list.push_back(temp);


}

void objectlist::renderlist()
{
	object* temp;
	for(int count = 0;count < list.size();count++)
	{
		temp = list[count];
		temp->render();
	}

}
