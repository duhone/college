// objectlist.h: interface for the objectlist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBJECTLIST_H__D2653E63_2A75_48C4_BFD5_FC0B173E11A4__INCLUDED_)
#define AFX_OBJECTLIST_H__D2653E63_2A75_48C4_BFD5_FC0B173E11A4__INCLUDED_


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

/*Abstraction for a list of objects. vector is used, so inserts and deletions are slow 
	however looping through the list is fast. A single object can be added to the list
	more than once. each copy will get its own modelview matrix, but will share thier 
	object information*/
class objectlist  
{
public:
	void transobj(int index,float x,float y,float z);
		/*translate the object held at position index using the passed values*/
	void scaleobj(int index,float x,float y,float z);
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
	vector<object*> list;
		/*vector to hold the objects*/
	vector<transvector*> translist;
		/*vector to hold the translation matrix data*/
	vector<scalevector*> scalelist;
		/*vector to hold the scaleing matrix data*/
};

#endif // !defined(AFX_OBJECTLIST_H__D2653E63_2A75_48C4_BFD5_FC0B173E11A4__INCLUDED_)
