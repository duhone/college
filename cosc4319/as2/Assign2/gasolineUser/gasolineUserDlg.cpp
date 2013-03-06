// gasolineUserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gasolineUser.h"
#include "gasolineUserDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGasolineUserDlg dialog

CGasolineUserDlg::CGasolineUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGasolineUserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGasolineUserDlg)
	m_drainAmount = 0.0;
	m_fillAmount = 0.0;
	m_premiumLevel = 0.0;
	m_regularLevel = 0.0;
	m_supremeLevel = 0.0;
	m_drainGrade = -1;
	m_fillGrade = -1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGasolineUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGasolineUserDlg)
	DDX_Text(pDX, IDC_EDIT_AMOUNT, m_drainAmount);
	DDX_Text(pDX, IDC_EDIT_AMOUNT_FILL, m_fillAmount);
	DDX_Text(pDX, IDC_EDIT_PREMIUM_LEVEL, m_premiumLevel);
	DDX_Text(pDX, IDC_EDIT_REGULAR_LEVEL, m_regularLevel);
	DDX_Text(pDX, IDC_EDIT_SUPREME_LEVEL, m_supremeLevel);
	DDX_Radio(pDX, IDC_RADIO_REGULAR, m_drainGrade);
	DDX_Radio(pDX, IDC_RADIO_REGULAR_FILL, m_fillGrade);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGasolineUserDlg, CDialog)
	//{{AFX_MSG_MAP(CGasolineUserDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_DRAIN, OnButtonDrain)
	ON_BN_CLICKED(IDC_BUTTON_FILL, OnButtonFill)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGasolineUserDlg message handlers

BOOL CGasolineUserDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	HRESULT hr;

	CLSID clsid;
	hr = ::CLSIDFromProgID(L"GasolineReservoirComp.GasolineReservoir", &clsid);

	if (hr == S_OK)
	{
		hr = ::CoCreateInstance(clsid, NULL, CLSCTX_INPROC_SERVER,
			IID_IGasFiller, (void**) &m_pGasFiller);

		if (hr != S_OK)
		{
			AfxMessageBox("Error creating COM object");
			return FALSE;
		}
	}
	else
	{
		AfxMessageBox("Error getting clsid for GasolineReservoirComp.GasolineReservoir");
		return FALSE;
	}
	
	updateLevels();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGasolineUserDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGasolineUserDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGasolineUserDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGasolineUserDlg::updateLevels()
{
	UpdateData(TRUE);

	m_pGasFiller->getGasLevel(0, &m_regularLevel);
	m_pGasFiller->getGasLevel(1, &m_premiumLevel);
	m_pGasFiller->getGasLevel(2, &m_supremeLevel);

	UpdateData(FALSE);
}

void CGasolineUserDlg::OnButtonDrain() 
{
	CWaitCursor cursor;

	UpdateData(TRUE);

	if (m_drainGrade < 0)
	{
		AfxMessageBox("Specify grade to drain");
		return;
	}

	if (m_drainAmount > 0)
	{
		CComQIPtr<IGasReservoir, &IID_IGasReservoir> pGasReservoir(m_pGasFiller);

		if (pGasReservoir != 0)
		{
			GetDlgItem(IDC_BUTTON_DRAIN)->EnableWindow(FALSE);
			pGasReservoir->drainGas(m_drainGrade, m_drainAmount);
			GetDlgItem(IDC_BUTTON_DRAIN)->EnableWindow(TRUE);
		}

		updateLevels();
	}
	else
	{
		AfxMessageBox("Specify Amount to drain");
	}
}

void CGasolineUserDlg::OnButtonFill() 
{
	CWaitCursor cursor;

	UpdateData(TRUE);

	if (m_fillGrade < 0)
	{
		AfxMessageBox("Specify grade to fill");
		return;
	}

	if (m_fillAmount > 0)
	{
		GetDlgItem(IDC_BUTTON_FILL)->EnableWindow(FALSE);
		m_pGasFiller->fillTank(m_fillGrade, m_fillAmount);
		GetDlgItem(IDC_BUTTON_FILL)->EnableWindow(TRUE);

		updateLevels();
	}
	else
	{
		AfxMessageBox("Specify Amount to drain");
	}
}
