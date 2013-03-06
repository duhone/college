// gasolineUserDlg.h : header file
//

#if !defined(AFX_GASOLINEUSERDLG_H__E2715FD4_C32A_11D3_87A0_A0EC0BC10000__INCLUDED_)
#define AFX_GASOLINEUSERDLG_H__E2715FD4_C32A_11D3_87A0_A0EC0BC10000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\gasolineInterfaces\gasolineInterfaces.h"
#include <atlbase.h>

/////////////////////////////////////////////////////////////////////////////
// CGasolineUserDlg dialog

class CGasolineUserDlg : public CDialog
{
// Construction
public:
	CGasolineUserDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGasolineUserDlg)
	enum { IDD = IDD_GASOLINEUSER_DIALOG };
	double	m_drainAmount;
	double	m_fillAmount;
	double	m_premiumLevel;
	double	m_regularLevel;
	double	m_supremeLevel;
	int		m_drainGrade;
	int		m_fillGrade;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGasolineUserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGasolineUserDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonDrain();
	afx_msg void OnButtonFill();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CComPtr<IGasFiller> m_pGasFiller;

	void updateLevels();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GASOLINEUSERDLG_H__E2715FD4_C32A_11D3_87A0_A0EC0BC10000__INCLUDED_)
