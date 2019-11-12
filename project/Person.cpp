// Person.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Person.h"
#include "PersonDlg.h"
#include "SkinHook.h"
#include "LoginDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPersonApp

BEGIN_MESSAGE_MAP(CPersonApp, CWinApp)
	//{{AFX_MSG_MAP(CPersonApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPersonApp construction

CPersonApp::CPersonApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPersonApp object

CPersonApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CPersonApp initialization

BOOL CPersonApp::InitInstance()
{
	AfxEnableControlContainer();

#ifdef _AFXDLL
	Enable3dControls();	
#else
	Enable3dControlsStatic();
#endif
	LoadSkin();

	BOOL bCon = GetConnection()->Open(GetConnection()->GetSQLConStr("127.0.0.1","tb_person"));//
	CLoginDialog logindlg;
	if (logindlg.DoModal() != IDOK)
		return false;
	CPersonDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{

	}
	else if (nResponse == IDCANCEL)
	{

	}
	return FALSE;
}
