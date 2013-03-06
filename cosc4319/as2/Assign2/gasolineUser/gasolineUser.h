// gasolineUser.h : main header file for the GASOLINEUSER application
//

#if !defined(AFX_GASOLINEUSER_H__E2715FD2_C32A_11D3_87A0_A0EC0BC10000__INCLUDED_)
#define AFX_GASOLINEUSER_H__E2715FD2_C32A_11D3_87A0_A0EC0BC10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGasolineUserApp:
// See gasolineUser.cpp for the implementation of this class
//

class CGasolineUserApp : public CWinApp
{
public:
	CGasolineUserApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGasolineUserApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGasolineUserApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GASOLINEUSER_H__E2715FD2_C32A_11D3_87A0_A0EC0BC10000__INCLUDED_)
