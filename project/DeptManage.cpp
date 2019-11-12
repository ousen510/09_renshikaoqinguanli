// DeptManage.cpp : implementation file
//

#include "stdafx.h"
#include "Person.h"
#include "DeptManage.h"
#include "DeptEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeptManage dialog


CDeptManage::CDeptManage(CWnd* pParent /*=NULL*/)
	: CDialog(CDeptManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDeptManage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDeptManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeptManage)
	DDX_Control(pDX, IDC_TREEDEPT, m_tree);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDeptManage, CDialog)
	//{{AFX_MSG_MAP(CDeptManage)
	ON_BN_CLICKED(IDC_APPEND, OnAdd)
	ON_BN_CLICKED(IDC_EDIT, OnEdit)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeptManage message handlers

BOOL CDeptManage::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_DataSet.SetConnection(::GetConnection());	
	UpdateDept();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDeptManage::UpdateDept()
{
	m_tree.DeleteAllItems();
	GetNode(TVI_ROOT,0);
}

void CDeptManage::GetNode(HTREEITEM pNode,int nPid)
{
	HTREEITEM node;
	
	CADODataSet DataSet;
	DataSet.SetConnection(::GetConnection());
	CString str;
	str.Format("Select * From tab_Dept where pid = %d",nPid);
	DataSet.Open(str);
	int count = DataSet.GetRecordCount();
	int ID;
	_variant_t value;
	for (int i = 0;i<count;i++)
	{
		node = m_tree.InsertItem((_bstr_t)DataSet.GetFields()->Item["DeptName"]->Value,pNode);
		value = (_variant_t)DataSet.GetFields()->Item["ID"]->Value;
		ID = value.intVal;
		m_tree.SetItemData(node,ID);
		GetNode(node,ID);
		DataSet.Next();
	}
}

void CDeptManage::OnAdd() 
{
	CDeptEdit deptedit;
	if (deptedit.DoModal() == IDOK)
	{
		HTREEITEM pNode = m_tree.GetSelectedItem();
		int pID;
		if (deptedit.isroot)
			pID = 0;
		else
			pID = m_tree.GetItemData(pNode);

		CADODataSet dataset;
		dataset.SetConnection(::GetConnection());
		dataset.Open("Select top 1 * From tab_Dept");
		dataset.AddNew();
		dataset.SetFieldValue("DeptName",(_variant_t)deptedit.name);
		dataset.SetFieldValue("memo",(_variant_t)deptedit.memo);
		dataset.SetFieldValue("PID",(long)pID);
		dataset.Save();
		UpdateDept();
	}
}

void CDeptManage::OnEdit() 
{
	CDeptEdit deptedit;
	deptedit.visible = false;

	HTREEITEM pNode = m_tree.GetSelectedItem();
	if (pNode == 0)
		return;
	int pID = m_tree.GetItemData(pNode);
	CADODataSet dataset;
	dataset.SetConnection(::GetConnection());
	CString str;
	str.Format("Select * From tab_Dept where id = %d",pID);
	dataset.Open(str);
	deptedit.name = (char *)(_bstr_t)dataset.GetFields()->Item[L"DeptName"]->Value;
	deptedit.memo = (char *)(_bstr_t)dataset.GetFields()->Item["memo"]->Value;
	if (deptedit.DoModal() == IDOK)
	{
		dataset.SetFieldValue("DeptName",(_variant_t)deptedit.name);
		dataset.SetFieldValue("memo",(_variant_t)deptedit.memo);
		dataset.Save();
		UpdateDept();
	}
}

void CDeptManage::OnDelete() 
{
	HTREEITEM pNode = m_tree.GetSelectedItem();
	if (pNode == 0)
		return;
	if (MessageBox("是否删除此记录！","提示",
		MB_YESNO|MB_ICONWARNING) == IDYES)
	{
		int pID = m_tree.GetItemData(pNode);
		CADODataSet dataset;
		dataset.SetConnection(::GetConnection());
		CString str;
		str.Format("Select * From tab_Dept where id = %d",pID);
		dataset.Open(str);	
		dataset.Delete();
		dataset.Save();
		UpdateDept();
	}
}
