// object.h: interface for the object class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBJECT_H__844B1C9F_36A5_4F59_9414_730096AA2760__INCLUDED_)
#define AFX_OBJECT_H__844B1C9F_36A5_4F59_9414_730096AA2760__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class object  
{
public:
	void setColorArray(float *array,int size);
	void render();
	void setVertexArray(float *array,int size);
	object();
	virtual ~object();

private:
	int colorsize;
	float * colorarray;
	int vertexsize;
	float * vertexPos;
};

#endif // !defined(AFX_OBJECT_H__844B1C9F_36A5_4F59_9414_730096AA2760__INCLUDED_)
