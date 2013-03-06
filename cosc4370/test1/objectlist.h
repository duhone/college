// objectlist.h: interface for the objectlist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBJECTLIST_H__D2653E63_2A75_48C4_BFD5_FC0B173E11A4__INCLUDED_)
#define AFX_OBJECTLIST_H__D2653E63_2A75_48C4_BFD5_FC0B173E11A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "object.h"

#include<vector>
using namespace std;

class objectlist  
{
public:
	void renderlist();
	void addobject(float *posdata,int possize,float *colordata,int colsize);
	objectlist();
	virtual ~objectlist();
private:
	vector<object*> list;

};

#endif // !defined(AFX_OBJECTLIST_H__D2653E63_2A75_48C4_BFD5_FC0B173E11A4__INCLUDED_)
