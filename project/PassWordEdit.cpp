// PassWordEdit.cpp : implementation file
//

#include "stdafx.h"
#include "Person.h"
#include "PassWordEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPassWordEdit dialog


CPassWordEdit::CPassWordEdit(CWnd* pParent /*=NULL*/)
	: CDialog(CPassWordEdit::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPassWordEdit)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPassWordEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPassWordEdit)
	DDX_Control(pDX, IDC_EDITPASS, m_password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPassWordEdit, CDialog)
	//{{AFX_MSG_MAP(CPassWordEdit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPassWordEdit message handlers

void CPassWordEdit::OnOK() 
{
	m_password.GetWindowText(PassWord);	
	m_DataSet.SetConnection(::GetConnection());
	CString str;
	str.Format("Select * From tab_User where UserName = '%s'",::GetUserName());
	m_DataSet.Open(str);
	m_DataSet.SetFieldValue("PassWord",(_bstr_t)PassWord);
	m_DataSet.Save();
	CDialog::OnOK();
}
