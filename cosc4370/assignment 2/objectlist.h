// objectlist.h: interface for the objectlist class.
//
//////////////////////////////////////////////////////////////////////
//NAME: Eric Duhon
//SSN:  453-97-8531

#if !defined OBJECTLIST_H
#define OBJECTLIST_H


#include<vector>
#include "object.h"

using namespace std;

struct transvector
/*structure to hold the values for a translation matrix*/
{
	float x,y,z;
	transvector() {x=0; y=0; z=0;}
};

struct scalevector
{
/*structure to hold the value for a scaling matrix*/
	float x,y,z;
	scalevector() {x=1; y=1; z=1;}
};

struct rotatevector
{
/*structure to hold the value for a rotation matrix*/
	float x,y,z;
	rotatevector() {x=0; y=0; z=0;}
};

struct colorvector
/*structure to hold the values for a color vector*/
{
	float r,g,b,a;
	colorvector() {r=0; g=0; b=0; a=1;}
};




/*Abstraction for a list of objects. vector is used, so inserts and deletions are slow 
	however looping through the list is fast. A single object can be added to the list
	more than once. each copy will get its own modelview matrix, but will share thier 
	object information*/
class objectlist  
{
public:
	void reset_view();
	void view_twist(float arg);
	void enable_object(int index,bool enable);
	void set_view_scale(float arg);
	void view_ltrt(float arg);
	void view_updn(float arg);
	void move_view_pos(float arg);
	void setwire(bool arg);
	void transobj(int index,float x,float y,float z);
		/*translate the object held at position index using the passed values*/
	void scaleobj(int index,float x,float y,float z);
		/*scale the object at position indes using the passed values*/
	void rotateobj(int index,float x,float y,float z);
		/*scale the object at position indes using the passed values*/
	void setcolor(int index,float r,float g,float b,float a);
		/*scale the object at position indes using the passed values*/
	void renderlist();
		/*render all the objects in the list*/
	void addobject(object* newobj);
		/*adds an object to the list*/
	objectlist();
		/*constructs a new empty list*/
	virtual ~objectlist();
		/*destroys the list releasing all objects in the list*/
private:
	GLfloat view_scale;
	GLfloat look_ltrt;
	GLfloat look_updn;
	GLfloat twist;
	GLfloat position;
	vector<object*> list;
		/*vector to hold the objects*/
	vector<transvector*> translist;
		/*vector to hold the translation matrix data*/
	vector<scalevector*> scalelist;
		/*vector to hold the scaleing matrix data*/
	vector<rotatevector*> rotatelist;
		/*vector to hold the scaleing matrix data*/
	vector<colorvector*> colorlist;
		/*vector to hold the scaleing matrix data*/
};

#endif // !defined(OBJECTLIST_H)
