// UserEdit.cpp : implementation file
//

#include "stdafx.h"
#include "Person.h"
#include "UserEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserEdit dialog


CUserEdit::CUserEdit(CWnd* pParent /*=NULL*/)
	: CDialog(CUserEdit::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserEdit)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CUserEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserEdit)
	DDX_Control(pDX, IDC_EDITPASSWORD, m_Password);
	DDX_Control(pDX, IDC_EDITUSERNAME, m_UserName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserEdit, CDialog)
	//{{AFX_MSG_MAP(CUserEdit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserEdit message handlers

void CUserEdit::OnOK() 
{
	m_UserName.GetWindowText(name);
	m_Password.GetWindowText(password);
	if (name.IsEmpty())
		AfxMessageBox("用户名不能为空！");
	else
		CDialog::OnOK();
}

BOOL CUserEdit::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_UserName.SetWindowText(name);	
	if (name == "mr")
	{
		m_UserName.EnableWindow(FALSE);
		m_Password.EnableWindow(FALSE);
	}
	else
	{
		m_Password.EnableWindow(FALSE);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
