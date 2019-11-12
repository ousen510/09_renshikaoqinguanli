// LoginDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Person.h"
#include "LoginDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDialog dialog


CLoginDialog::CLoginDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLoginDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDialog)
	DDX_Control(pDX, IDC_EDITPASSWORD, m_PassWord);
	DDX_Control(pDX, IDC_COMUSERLIST, m_UserList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDialog, CDialog)
	//{{AFX_MSG_MAP(CLoginDialog)
	ON_BN_CLICKED(IDOK, OnLogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDialog message handlers

void CLoginDialog::OnLogin() 
{
	CString sql,user,pass;
	m_UserList.GetWindowText(user);
	m_PassWord.GetWindowText(pass);

	sql.Format("Select * From tab_User Where UserName = '%s' and PassWord = '%s'",
		user,pass);
	m_DataSet.Open(sql);
	if (m_DataSet.GetRecordCount() == 1)
	{
		::SetUserName(user);
		this->OnOK();
	}
	else
		AfxMessageBox("用户名或密码不正确！");
}

BOOL CLoginDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_DataSet.SetConnection(GetConnection());
	m_DataSet.Open("Select * From tab_User");
	int count = m_DataSet.GetRecordCount();
	for (int i = 0; i< count;i++)
	{
		m_UserList.AddString((_bstr_t)m_DataSet.GetFields()->Item[L"UserName"]->Value);
		m_DataSet.Next();
	}
	m_UserList.SetCurSel(0);
	return TRUE; 
}
