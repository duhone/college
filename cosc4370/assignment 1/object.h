// object.h: interface for the object class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBJECT_H__844B1C9F_36A5_4F59_9414_730096AA2760__INCLUDED_)
#define AFX_OBJECT_H__844B1C9F_36A5_4F59_9414_730096AA2760__INCLUDED_

/*A polymorphistic class to handle the abtract concept of an object.*/


class object  
{
public:
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

private:
	int ref;
		/*keeps track of usage*/
};

#endif // !defined(AFX_OBJECT_H__844B1C9F_36A5_4F59_9414_730096AA2760__INCLUDED_)
