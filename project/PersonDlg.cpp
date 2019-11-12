// PersonDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Person.h"
#include "PersonDlg.h"
#include "usermanage.h"
#include "PassWordEdit.h"
#include "DeptManage.h"
#include "PersonManage.h"
#include "CheckManage.h"
#include "CheckSum.h"

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
// CPersonDlg dialog

CPersonDlg::CPersonDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPersonDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPersonDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPersonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPersonDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPersonDlg, CDialog)
	//{{AFX_MSG_MAP(CPersonDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_MENUUSER, OnMenuuser)
	ON_COMMAND(ID_MENUPASSWORD, OnMenupassword)
	ON_COMMAND(ID_MENUDEPT, OnMenudept)
	ON_COMMAND(ID_MENUPERSON, OnMenuperson)
	ON_COMMAND(ID_MENUEXIT, OnMenuexit)
	ON_COMMAND(ID_MENUCHECK, OnMenucheck)
	ON_COMMAND(ID_MENUCHECKSUM, OnMenuchecksum)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPersonDlg message handlers

BOOL CPersonDlg::OnInitDialog()
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
	m_Menu.LoadMenu(IDR_MAINMENU);
	this->SetMenu(&m_Menu);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPersonDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPersonDlg::OnPaint() 
{
	CPaintDC dc(this);
	if (IsIconic())
	{
		 // device context for painting

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

	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1);
	BITMAP bitmap;
	bmp.GetBitmap(&bitmap);
	CDC bmpdc;
	bmpdc.CreateCompatibleDC(&dc);
	bmpdc.SelectObject(&bmp);
	CRect rect;
	this->GetClientRect(&rect);
	dc.StretchBlt(rect.left,rect.top,rect.right,rect.bottom,&bmpdc,
		rect.left,rect.top,bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPersonDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPersonDlg::OnMenuuser() 
{
	CUserManage usermanage;
	usermanage.DoModal();
}

void CPersonDlg::OnMenupassword() 
{
	CPassWordEdit passwordedit;
	passwordedit.DoModal();
}

void CPersonDlg::OnMenudept() 
{
	CDeptManage deptmanage;
	deptmanage.DoModal();
}

void CPersonDlg::OnMenuperson() 
{
	CPersonManage personmanage;
	personmanage.DoModal();
}

void CPersonDlg::OnCancel() 
{
	if (MessageBox("确定要退出系统！","提示",
		MB_YESNO|MB_ICONWARNING) != IDYES)
		return;	
	CDialog::OnCancel();
}

void CPersonDlg::OnMenuexit() 
{
	this->OnCancel();
}


void CPersonDlg::OnMenucheck() 
{
	CCheckManage checkmanage;
	checkmanage.DoModal();
}

void CPersonDlg::OnMenuchecksum() 
{
	CCheckSum checksum;
	checksum.DoModal();
}

void CPersonDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	if (nType == SIZE_MAXIMIZED)
	{
		Invalidate();
	}
	else if (nType == SIZE_RESTORED)
	{
		Invalidate();
	}
}
