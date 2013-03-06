// object2d_p_c.h: interface for the object2d_p_c class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBJECT2D_P_C_H__58EDB843_953A_4F37_81F7_6DB5DC259B97__INCLUDED_)
#define AFX_OBJECT2D_P_C_H__58EDB843_953A_4F37_81F7_6DB5DC259B97__INCLUDED_

/*Class that represents a 2d object. Object contains both position and color information*/
#include "object.h"

class object2d_p_c : public object  
{
public:
	object2d_p_c();
		/*constructs a new 2d object. the object has no data*/
	virtual ~object2d_p_c();
		/*destroy object and release all memory*/
	void setColorArray(float *array,int size);
		/*sets the values of the color for the 2d object. Parameter
			array is copied into the object.size is the number of elemnts in array*/
	virtual void render();
		/*renders the 2d object using specifed position and color data.Do not call before 
			setting the vertexarray and the colorarray*/
	void setVertexArray(float *array,int size);
		/*sets the vertexarray(position data). Parameter array is copied into the object. 
			size is the number of elements to copy*/
private:
	int colorsize;
		/*number of color elements*/
	float * colorarray;
		/*array containing the color information*/
	int vertexsize;
		/*number of vertex elements*/
	float * vertexPos;
		/*array containing the vertex information*/

};

#endif // !defined(AFX_OBJECT2D_P_C_H__58EDB843_953A_4F37_81F7_6DB5DC259B97__INCLUDED_)
