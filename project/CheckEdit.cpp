// CheckEdit.cpp : implementation file
//

#include "stdafx.h"
#include "Person.h"
#include "CheckEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCheckEdit dialog


CCheckEdit::CCheckEdit(CWnd* pParent /*=NULL*/)
	: CDialog(CCheckEdit::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCheckEdit)
	m_leave = _T("");
	m_name = _T("");
	m_datecheck = 0;
	m_memo = _T("");
	m_timeoff = 0;
	m_timeoffduty = 0;
	m_timeoffleave = 0;
	m_timeon = 0;
	m_timeonduty = 0;
	m_timeonleave = 0;
	//}}AFX_DATA_INIT
}


void CCheckEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCheckEdit)
	DDX_Control(pDX, IDC_COMLEAVE, m_BoxLeave);
	DDX_Control(pDX, IDC_COMNAME, m_BoxName);
	DDX_CBString(pDX, IDC_COMLEAVE, m_leave);
	DDX_CBString(pDX, IDC_COMNAME, m_name);
	DDX_DateTimeCtrl(pDX, IDC_DATETCHECK, m_datecheck);
	DDX_Text(pDX, IDC_EMEMO, m_memo);
	DDX_DateTimeCtrl(pDX, IDC_TIMEOFF, m_timeoff);
	DDX_DateTimeCtrl(pDX, IDC_TIMEOFFDUTY, m_timeoffduty);
	DDX_DateTimeCtrl(pDX, IDC_TIMEOFFLEAVE, m_timeoffleave);
	DDX_DateTimeCtrl(pDX, IDC_TIMEON, m_timeon);
	DDX_DateTimeCtrl(pDX, IDC_TIMEONDUTY, m_timeonduty);
	DDX_DateTimeCtrl(pDX, IDC_TIMEONLEAVE, m_timeonleave);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCheckEdit, CDialog)
	//{{AFX_MSG_MAP(CCheckEdit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCheckEdit message handlers

BOOL CCheckEdit::OnInitDialog() 
{
	CDialog::OnInitDialog();
	this->UpdateData(false);
	CADODataSet dataset;
	dataset.SetConnection(::GetConnection());
	dataset.Open("Select * from tab_Employees");
	this->UpdateData();
	for (int i = 0; i < dataset.GetRecordCount() ; i++)
	{
		m_BoxName.AddString((_bstr_t)dataset.GetFields()->Item["Emp_NAME"]->Value);
		dataset.Next();
	}
	m_BoxLeave.InsertString(0,"ÎÞ");
	m_BoxLeave.InsertString(1,"ÊÂ¼Ù");
	m_BoxLeave.InsertString(2,"²¡¼Ù");

	if (m_leave.IsEmpty())
		m_BoxLeave.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCheckEdit::OnOK() 
{
	this->UpdateData();	
	CDialog::OnOK();
}
