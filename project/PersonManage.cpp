// PersonManage.cpp : implementation file
//

#include "stdafx.h"
#include "Person.h"
#include "PersonManage.h"
#include "PersonEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPersonManage dialog


CPersonManage::CPersonManage(CWnd* pParent /*=NULL*/)
	: CDialog(CPersonManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPersonManage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPersonManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPersonManage)
	DDX_Control(pDX, IDC_LISTPERSON, m_list);
	DDX_Control(pDX, IDC_TREEDEPT, m_tree);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPersonManage, CDialog)
	//{{AFX_MSG_MAP(CPersonManage)
	ON_BN_CLICKED(IDC_BUTTON2, OnAdd)
	ON_BN_CLICKED(IDC_BUTTON1, OnEdit)
	ON_BN_CLICKED(IDC_BUTTON3, OnDelete)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREEDEPT, OnSelchangedTreedept)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPersonManage message handlers

BOOL CPersonManage::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_DeptID = -1;
	UpdateDept();
	int i = 0;

	m_list.InsertColumn(i,"人员编号");
	m_list.SetColumnWidth(i++,80);

	m_list.InsertColumn(i,"人员名称");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"性别");
	m_list.SetColumnWidth(i++,50);

	m_list.InsertColumn(i,"民族");
	m_list.SetColumnWidth(i++,50);

	m_list.InsertColumn(i,"出生日期");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"政治面貌");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"文化程度");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"婚姻状况");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"身份证号");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"办公电话");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"手机电话");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"到岗日期");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"职务");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"备注");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"家庭住址");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"档案所在地");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"户口所在地");
	m_list.SetColumnWidth(i++,100);

	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	UpdatePerson();
	return TRUE; 
}

void CPersonManage::OnAdd() 
{
	CPersonEdit personedit;
	personedit.m_DeptData = m_DeptID;
	if (personedit.DoModal() == IDOK)
	{
		CADODataSet dataset;
		dataset.SetConnection(::GetConnection());
		CString str = "select top 1 * from tab_Employees";
		dataset.Open(str);
		dataset.AddNew();
		dataset.SetFieldValue("Emp_Id",(_bstr_t)personedit.m_id);
		dataset.SetFieldValue("Emp_NAME",(_bstr_t)personedit.m_name);
		dataset.SetFieldValue("Sex",(_bstr_t)personedit.m_sex);
		dataset.SetFieldValue("Nationality",(_bstr_t)personedit.m_nationality);
		dataset.SetFieldValue("Birth",(_bstr_t)personedit.m_birth.Format("%Y-%m-%d"));
		dataset.SetFieldValue("Political_Party",(_bstr_t)personedit.m_farty);
		dataset.SetFieldValue("Culture_Level",(_bstr_t)personedit.m_culture);
		dataset.SetFieldValue("Marital_Condition",(_bstr_t)personedit.m_marital);
		dataset.SetFieldValue("Id_Card",(_bstr_t)personedit.m_card);
		dataset.SetFieldValue("Office_phone",(_bstr_t)personedit.m_office);
		dataset.SetFieldValue("Mobile",(_bstr_t)personedit.m_mobile);
		dataset.SetFieldValue("HireDate",(_bstr_t)personedit.m_hire.Format("%Y-%m-%d"));
		dataset.SetFieldValue("Duty",(_bstr_t)personedit.m_duty);
		dataset.SetFieldValue("Memo",(_bstr_t)personedit.m_memo);
		dataset.SetFieldValue("Files_Keep_Org",(_bstr_t)personedit.m_files);
		dataset.SetFieldValue("Hukou",(_bstr_t)personedit.m_hukou);
		dataset.SetFieldValue("Family_Place",(_bstr_t)personedit.m_family);
		dataset.SetFieldValue("dept",personedit.m_DeptData);
		dataset.Save();
		UpdatePerson();
	}
}

void CPersonManage::OnEdit() 
{
	if (m_list.GetSelectionMark() == -1)
		return;
	int id = m_list.GetItemData(m_list.GetSelectionMark());
	CPersonEdit personedit;
	CADODataSet dataset;
	dataset.SetConnection(::GetConnection());
	CString str;
	str.Format("select * from tab_Employees where autoid = %d",id);
	dataset.Open(str);

	personedit.m_id = (char *)(_bstr_t)dataset.GetFields()->Item["Emp_Id"]->Value;
	personedit.m_name = (char *)(_bstr_t)dataset.GetFields()->Item["Emp_NAME"]->Value;
	personedit.m_sex = (char *)(_bstr_t)dataset.GetFields()->Item["Sex"]->Value;
	personedit.m_nationality = (char *)(_bstr_t)dataset.GetFields()->Item["Nationality"]->Value;
	CString birth = (char *)(_bstr_t)dataset.GetFields()->Item["Birth"]->Value;
	if (!birth.IsEmpty())
	{
		//设置日期数据
		int yy=atoi(birth.Left(4));
		int mm=atoi(birth.Mid(6,2));
		int dd=atoi(birth.Mid(9,2));
		CTime tbirth(yy,mm,dd,0,0,0);
		personedit.m_birth = tbirth;
	}
	personedit.m_farty = (char *)(_bstr_t)dataset.GetFields()->Item["Political_Party"]->Value;
	personedit.m_culture = (char *)(_bstr_t)dataset.GetFields()->Item["Culture_Level"]->Value;
	personedit.m_marital = (char *)(_bstr_t)dataset.GetFields()->Item["Marital_Condition"]->Value;
	personedit.m_card = (char *)(_bstr_t)dataset.GetFields()->Item["Id_Card"]->Value;
	personedit.m_office = (char *)(_bstr_t)dataset.GetFields()->Item["Office_phone"]->Value;
	personedit.m_mobile = (char *)(_bstr_t)dataset.GetFields()->Item["Mobile"]->Value;
	CString hire = (char *)(_bstr_t)dataset.GetFields()->Item["HireDate"]->Value;
	if (!hire.IsEmpty())
	{
		//设置日期数据
		int yy=atoi(hire.Left(4));
		int mm=atoi(hire.Mid(6,2));
		int dd=atoi(hire.Mid(9,2));
		CTime thire(yy,mm,dd,0,0,0);
		personedit.m_hire = thire;
	}
	personedit.m_duty = (char *)(_bstr_t)dataset.GetFields()->Item["Duty"]->Value;
	personedit.m_memo = (char *)(_bstr_t)dataset.GetFields()->Item["Memo"]->Value;
	personedit.m_files = (char *)(_bstr_t)dataset.GetFields()->Item["Files_Keep_Org"]->Value;
	personedit.m_hukou = (char *)(_bstr_t)dataset.GetFields()->Item["Hukou"]->Value;
	personedit.m_family = (char *)(_bstr_t)dataset.GetFields()->Item["Family_Place"]->Value;
	personedit.m_DeptData = dataset.GetFields()->Item["Dept"]->Value;

	if (personedit.DoModal() == IDOK)
	{
		dataset.SetFieldValue("Emp_Id",(_bstr_t)personedit.m_id);
		dataset.SetFieldValue("Emp_NAME",(_bstr_t)personedit.m_name);
		dataset.SetFieldValue("Sex",(_bstr_t)personedit.m_sex);
		dataset.SetFieldValue("Nationality",(_bstr_t)personedit.m_nationality);
		dataset.SetFieldValue("Birth",(_bstr_t)personedit.m_birth.Format("%Y-%m-%d"));
		dataset.SetFieldValue("Political_Party",(_bstr_t)personedit.m_farty);
		dataset.SetFieldValue("Culture_Level",(_bstr_t)personedit.m_culture);
		dataset.SetFieldValue("Marital_Condition",(_bstr_t)personedit.m_marital);
		dataset.SetFieldValue("Id_Card",(_bstr_t)personedit.m_card);
		dataset.SetFieldValue("Office_phone",(_bstr_t)personedit.m_office);
		dataset.SetFieldValue("Mobile",(_bstr_t)personedit.m_mobile);
		dataset.SetFieldValue("HireDate",(_bstr_t)personedit.m_hire.Format("%Y-%m-%d"));
		dataset.SetFieldValue("Duty",(_bstr_t)personedit.m_duty);
		dataset.SetFieldValue("Memo",(_bstr_t)personedit.m_memo);
		dataset.SetFieldValue("Files_Keep_Org",(_bstr_t)personedit.m_files);
		dataset.SetFieldValue("Hukou",(_bstr_t)personedit.m_hukou);
		dataset.SetFieldValue("Family_Place",(_bstr_t)personedit.m_family);
		dataset.SetFieldValue("dept",personedit.m_DeptData);
		dataset.Save();
		UpdatePerson();
	}	
}

void CPersonManage::OnDelete() 
{
	if (MessageBox("是否删除此记录！","提示",
		MB_YESNO|MB_ICONWARNING) == IDYES)
	{
		if (m_list.GetSelectionMark() == -1)
			return;
		int id = m_list.GetItemData(m_list.GetSelectionMark());
		CADODataSet dataset;
		dataset.SetConnection(::GetConnection());
		CString str;
		str.Format("select * from tab_Employees where autoid = %d",id);
		dataset.Open(str);
		dataset.Delete();
		dataset.Save();
		UpdatePerson();
	}
}

void CPersonManage::UpdateDept()
{
	m_tree.DeleteAllItems();
	HTREEITEM node;
	node = m_tree.InsertItem("全部",TVI_ROOT);
	m_tree.SetItemData(node,-1);
	GetNode(node,0);
}

void CPersonManage::GetNode(HTREEITEM pNode, int nPid)
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

void CPersonManage::UpdatePerson()
{
	m_list.DeleteAllItems();
	CADODataSet DataSet;
	DataSet.SetConnection(::GetConnection());
	CString str;
	if (m_DeptID == -1)
		str.Format("Select * From tab_Employees");
	else
		str.Format("Select * From tab_Employees where Dept = %d",m_DeptID);
	DataSet.Open(str);
	int count = DataSet.GetRecordCount();
	int n = 0;
	_variant_t value;
	for (int i = 0;i<count;i++)
	{
		int index = 1;
		m_list.InsertItem(n,(_bstr_t)DataSet.GetFields()->Item["Emp_Id"]->Value);
		value = DataSet.GetFields()->Item["AutoID"]->Value;
		m_list.SetItemData(n,value.lVal);
		m_list.SetItemText(n,index++,(_bstr_t)DataSet.GetFields()->Item["Emp_NAME"]->Value);
		m_list.SetItemText(n,index++,(_bstr_t)DataSet.GetFields()->Item["Sex"]->Value);
		m_list.SetItemText(n,index++,(_bstr_t)DataSet.GetFields()->Item["Nationality"]->Value);
		m_list.SetItemText(n,index++,(_bstr_t)DataSet.GetFields()->Item["Birth"]->Value);
		m_list.SetItemText(n,index++,(_bstr_t)DataSet.GetFields()->Item["Political_Party"]->Value);
		m_list.SetItemText(n,index++,(_bstr_t)DataSet.GetFields()->Item["Culture_Level"]->Value);
		m_list.SetItemText(n,index++,(_bstr_t)DataSet.GetFields()->Item["Marital_Condition"]->Value);
		m_list.SetItemText(n,index++,(_bstr_t)DataSet.GetFields()->Item["Id_Card"]->Value);
		m_list.SetItemText(n,index++,(_bstr_t)DataSet.GetFields()->Item["Office_phone"]->Value);
		m_list.SetItemText(n,index++,(_bstr_t)DataSet.GetFields()->Item["Mobile"]->Value);
		m_list.SetItemText(n,index++,(_bstr_t)DataSet.GetFields()->Item["HireDate"]->Value);
		m_list.SetItemText(n,index++,(_bstr_t)DataSet.GetFields()->Item["Duty"]->Value);
		m_list.SetItemText(n,index++,(_bstr_t)DataSet.GetFields()->Item["Memo"]->Value);
		m_list.SetItemText(n,index++,(_bstr_t)DataSet.GetFields()->Item["Files_Keep_Org"]->Value);
		m_list.SetItemText(n,index++,(_bstr_t)DataSet.GetFields()->Item["Hukou"]->Value);
		m_list.SetItemText(n,index++,(_bstr_t)DataSet.GetFields()->Item["Family_Place"]->Value);

		n++;
		DataSet.Next();
	}
}

void CPersonManage::OnSelchangedTreedept(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	m_DeptID = m_tree.GetItemData(pNMTreeView->itemNew.hItem);
	UpdatePerson();
	*pResult = 0;
}
