// UserManage.cpp : implementation file
//

#include "stdafx.h"
#include "Person.h"
#include "UserManage.h"
#include "UserEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserManage dialog


CUserManage::CUserManage(CWnd* pParent /*=NULL*/)
	: CDialog(CUserManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserManage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CUserManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserManage)
	DDX_Control(pDX, IDC_LISTGRID, m_grid);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserManage, CDialog)
	//{{AFX_MSG_MAP(CUserManage)
	ON_BN_CLICKED(IDC_APPEND, OnAppend)
	ON_BN_CLICKED(IDC_EDIT, OnEdit)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserManage message handlers

BOOL CUserManage::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_grid.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	m_grid.InsertColumn(0,"用户名");
	m_grid.SetColumnWidth(0,150);
	
	m_DataSet.SetConnection(::GetConnection());	
	UpdateGrid();
	return TRUE;  
}

void CUserManage::UpdateGrid()
{
	m_DataSet.Open("Select * From tab_User");
	m_grid.DeleteAllItems();
	for (int i = 0 ; i < m_DataSet.GetRecordCount();i++)
	{
		m_grid.InsertItem(i,(_bstr_t)m_DataSet.GetFields()->Item[L"UserName"]->Value);
		int no = m_DataSet.GetRecordNo();
		m_grid.SetItemData(i,no);
		m_DataSet.Next();
	}
}

void CUserManage::OnAppend() 
{
	CUserEdit useredit;
	if (useredit.DoModal() == IDOK)
	{
		m_DataSet.AddNew();
		m_DataSet.SetFieldValue("UserName",(_bstr_t)useredit.name);
		m_DataSet.SetFieldValue("PassWord",(_bstr_t)useredit.password);
		m_DataSet.Save();
		UpdateGrid();
	}
}

void CUserManage::OnEdit() 
{
	int pos = m_grid.GetSelectionMark();
	if (pos != -1)
	{
		CUserEdit useredit;
		int no = m_grid.GetItemData(m_grid.GetSelectionMark());
		m_DataSet.move(no-1);
		useredit.name = (char *)(_bstr_t)m_DataSet.GetFields()->Item[L"UserName"]->Value;
		if (useredit.DoModal() == IDOK)
		{
			m_DataSet.SetFieldValue("UserName",(_bstr_t)useredit.name);
			m_DataSet.Save();
			UpdateGrid();
		}
	}
}

void CUserManage::OnDelete() 
{
	int pos = m_grid.GetSelectionMark();
	if (pos != -1)
	{
		CString name = m_grid.GetItemText(pos,0);
		if (name != "mr")
		{
			if (MessageBox("是否删除此记录！","提示",
				MB_YESNO|MB_ICONWARNING) == IDYES)
			{
				int no = m_grid.GetItemData(m_grid.GetSelectionMark());
				m_DataSet.move(no-1);
				m_DataSet.Delete();
				m_DataSet.Save();
				UpdateGrid();
			}
		}
		else
		{
			MessageBox("该用户不能删除！");
			return;
		}
	}
}
