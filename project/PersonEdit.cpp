// PersonEdit.cpp : implementation file
//

#include "stdafx.h"
#include "Person.h"
#include "PersonEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPersonEdit dialog


CPersonEdit::CPersonEdit(CWnd* pParent /*=NULL*/)
	: CDialog(CPersonEdit::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPersonEdit)
	m_id = _T("");
	m_marital = _T("");
	m_sex = _T("");
	m_birth = 0;
	m_hire = 0;
	m_card = _T("");
	m_culture = _T("");
	m_duty = _T("");
	m_family = _T("");
	m_farty = _T("");
	m_files = _T("");
	m_hukou = _T("");
	m_memo = _T("");
	m_mobile = _T("");
	m_name = _T("");
	m_nationality = _T("");
	m_office = _T("");
	//}}AFX_DATA_INIT
}


void CPersonEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPersonEdit)
	DDX_Control(pDX, IDC_CDEPT, m_CombDept);
	DDX_Control(pDX, IDC_CMARITAL, m_CombMarital);
	DDX_Control(pDX, IDC_CSEX, m_CombSex);
	DDX_Text(pDX, IDC_EID, m_id);
	DDX_CBString(pDX, IDC_CMARITAL, m_marital);
	DDX_CBString(pDX, IDC_CSEX, m_sex);
	DDX_DateTimeCtrl(pDX, IDC_DBIRTH, m_birth);
	DDX_DateTimeCtrl(pDX, IDC_DHIRE, m_hire);
	DDX_Text(pDX, IDC_ECARD, m_card);
	DDX_Text(pDX, IDC_ECULTURE, m_culture);
	DDX_Text(pDX, IDC_EDUTY, m_duty);
	DDX_Text(pDX, IDC_EFAMILY, m_family);
	DDX_Text(pDX, IDC_EFARTY, m_farty);
	DDX_Text(pDX, IDC_EFILES, m_files);
	DDX_Text(pDX, IDC_EHUKOU, m_hukou);
	DDX_Text(pDX, IDC_EMEMO, m_memo);
	DDX_Text(pDX, IDC_EMOBILE, m_mobile);
	DDX_Text(pDX, IDC_ENAME, m_name);
	DDX_Text(pDX, IDC_ENATIONALITY, m_nationality);
	DDX_Text(pDX, IDC_EOFFICE, m_office);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPersonEdit, CDialog)
	//{{AFX_MSG_MAP(CPersonEdit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPersonEdit message handlers

void CPersonEdit::OnOK() 
{
	this->UpdateData();
	if (m_id.IsEmpty())
	{
		MessageBox("“人员编号”不能为空！","提示",MB_ICONWARNING);
		return;
	}
	if (m_name.IsEmpty())
	{
		MessageBox("“人员姓名”不能为空！","提示",MB_ICONWARNING);
		return;
	}
	if (m_birth.GetYear() <= 1970)
	{
		MessageBox("日期必需大于1970年！","提示",MB_ICONWARNING);
		return;
	}
	if (m_hire.GetYear() <= 1970)
	{
		MessageBox("日期必需大于1970年！","提示",MB_ICONWARNING);
		return;
	}	
	int sel = m_CombDept.GetCurSel();
	m_DeptData = m_CombDept.GetItemData(sel);
	CDialog::OnOK();
}

BOOL CPersonEdit::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	this->UpdateData(false);
	m_CombSex.AddString("男");
	m_CombSex.AddString("女");
	if (m_CombSex.GetCurSel() == -1)
	{
		m_CombSex.SetCurSel(0);
	}
	m_CombMarital.AddString("未婚");
	m_CombMarital.AddString("已婚");
	m_CombMarital.AddString("离异");
	if (m_CombMarital.GetCurSel() == -1)
	{
		m_CombMarital.SetCurSel(0);
	}
	CADODataSet dataset;
	dataset.SetConnection(::GetConnection());
	dataset.Open("Select * From tab_dept");
	for (int i = 0 ; i<dataset.GetRecordCount();i++)
	{
		int index = m_CombDept.AddString((_bstr_t)dataset.GetFields()->Item["DeptName"]->Value);
		long ID = (_variant_t)dataset.GetFields()->Item["ID"]->Value;
		if (ID == m_DeptData)
			m_CombDept.SetCurSel(index);
		m_CombDept.SetItemData(index,ID);
		dataset.Next();
	}
	if (m_CombDept.GetCurSel() == -1)
	{
		m_CombDept.SetCurSel(0);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
