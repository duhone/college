// object.h: interface for the object class.
//
//////////////////////////////////////////////////////////////////////
//NAME: Eric Duhon
//SSN:  453-97-8531

#if !defined OBJECT_H
#define OBJECT_H

/*A polymorphistic class to handle the abtract concept of an object.*/

#include "gl\glut.h"

class object  
{
public:
	virtual void enable_object(bool arg);
		/*Enable the object to be drawn on the screen*/
	virtual void set_wire(bool arg) = 0;
		/*Draw wireframe or not*/
	void addRef();
		/*Lets the object know that another pointer has been assigned the adress of this
			object*/
	void Release();
		/*Lets the object know that a pointer to this object is no longer needed. If there
			are no more pointers to this object the object will selfdestruct.*/
	virtual void render() = 0;
		/*pure virtual function to render the object. Must be implemented in all 
			derived classes*/
	object();
		/*constructer. sets usage to 0, so make sure to call addref to increment usage if needed*/
	virtual ~object();
		/*destructor*/

protected:
	bool enabled;

private:
	int ref;
		/*keeps track of usage*/
};

#endif // !defined(OBJECT_H)
