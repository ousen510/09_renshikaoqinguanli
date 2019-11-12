// CheckSum.cpp : implementation file
//

#include "stdafx.h"
#include "Person.h"
#include "CheckSum.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCheckSum dialog


CCheckSum::CCheckSum(CWnd* pParent /*=NULL*/)
	: CDialog(CCheckSum::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCheckSum)
	m_emp = _T("");
	m_mm = _T("");
	m_yy = _T("");
	//}}AFX_DATA_INIT
}


void CCheckSum::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCheckSum)
	DDX_Control(pDX, IDC_LISTEMP, m_list);
	DDX_Control(pDX, IDC_CYY, m_cyy);
	DDX_Control(pDX, IDC_CMM, m_cmm);
	DDX_Control(pDX, IDC_CEMP, m_cemp);
	DDX_CBString(pDX, IDC_CEMP, m_emp);
	DDX_CBString(pDX, IDC_CMM, m_mm);
	DDX_CBString(pDX, IDC_CYY, m_yy);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCheckSum, CDialog)
	//{{AFX_MSG_MAP(CCheckSum)
	ON_CBN_CLOSEUP(IDC_CEMP, OnCloseupCemp)
	ON_CBN_CLOSEUP(IDC_CYY, OnCloseupCyy)
	ON_CBN_CLOSEUP(IDC_CMM, OnCloseupCmm)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCheckSum message handlers

BOOL CCheckSum::OnInitDialog() 
{
	CDialog::OnInitDialog();

	int i = 0;
	m_list.InsertColumn(i,"人员姓名");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"工作总天数");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"迟到总天数");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"早退总天数");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"病假总天数");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"事假总天数");
	m_list.SetColumnWidth(i++,100);

	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	int curyear,curmonth;
	CTime time(CTime::GetCurrentTime());
	curyear = time.GetYear();
	curmonth = time.GetMonth();

	char value[10];
	for (int y = 2000; y < 2100 ;y++)
	{
		_itoa(y,value,10);
		m_cyy.InsertString(y-2000,value);
	}
	m_cyy.SetCurSel(curyear-2000);
	for (int n = 1 ; n<=12 ;n++)
	{
		_itoa(n,value,10);
		m_cmm.InsertString(n-1,value);
	}
	m_cmm.SetCurSel(curmonth-1);

	CADODataSet dataset;
	dataset.SetConnection(::GetConnection());
	dataset.Open("Select * From tab_Employees");
	m_cemp.InsertString(0,"(全部)");
	for (int index = 1 ; index <= dataset.GetRecordCount() ; index++)
	{
		m_cemp.InsertString(index,(_bstr_t)dataset.GetFields()->Item["emp_name"]->Value);
		dataset.Next();
	}
	m_cemp.SetCurSel(0);

	UpdateList();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCheckSum::UpdateList()
{
	m_list.DeleteAllItems();
	this->UpdateData();
	CADODataSet dataset;
	dataset.SetConnection(::GetConnection());
	CString str,temp,where,datestr,StartDate,EndDate;
	StartDate = m_yy + "-" + m_mm + "-1" ;
	EndDate.Format("DATEADD(month,1,'%s')",StartDate);
	datestr.Format(" between '%s' and %s",StartDate,EndDate);

	//*/
	temp += "select emp.emp_name ,ROUND(isnull(works.workday,0),2)";
	temp += " workday,ROUND(isnull(lates.lateday,0),2) lateday,";
	temp += " ROUND(isnull(leaveearlys.leaveearlyday,0),2) leaveearlyday,";
	temp += " ROUND(isnull(bjdays.bjday,0),2) bjday,ROUND(isnull(sjdays.sjday,0),2) sjday";
	temp += " from tab_Employees emp ";
	temp += " left join";
	temp += " (select sum(DATEDIFF(second,ontime,offtime)) / 60.0 / 60.0 / 8.0";
	temp += " as workday,name  From tab_Check where checkdate %s group by name)";
	temp += " works on emp.emp_name = works.name";
	temp += " left join";
	temp += " (select (sum(DATEPART(Hour,latetime)) * 60 * 60 + ";
	temp += " sum(DATEPART(minute,latetime)) * 60 + sum(DATEPART(second,latetime)))";
	temp += " /60.0 /60.0 /8.0 as lateday,name   From tab_Check where checkdate";
	temp += " %s group by name) lates on emp.emp_name = lates.name";
	temp += " left join";
	temp += " (select (sum(DATEPART(Hour,leaveearly)) * 60 * 60 + ";
	temp += " sum(DATEPART(minute,leaveearly)) * 60 + sum(DATEPART(second,leaveearly)))";
	temp += " /60.0 /60.0 /8.0  as leaveearlyday,name   From tab_Check where ";
	temp += " checkdate %s group by name) leaveearlys on emp.emp_name";
	temp += " = leaveearlys.name";
	temp += " left join";
	temp += " (select isnull(sum(DATEDIFF(second,onleave,offleave))";
	temp += " / 60.0 / 60.0 / 8.0,0) as bjday,name  From tab_Check where";
	temp += " leave = '病假' and checkdate %s group by name) ";
	temp += " bjdays on emp.emp_name = bjdays.name";
	temp += " left join";
	temp += " (select isnull(sum(DATEDIFF(second,onleave,offleave)) ";
	temp += " / 60.0 / 60.0 / 8.0,0) as sjday,name  From tab_Check where ";
	temp += " leave = '事假' and checkdate %s group by name) ";
	temp += " sjdays on emp.emp_name = sjdays.name";
	temp += " %s";//*/
	//
	where.Format(" where emp.emp_name = '%s'",m_emp);
	if (m_emp == "(全部)") 
		str.Format(temp,datestr,datestr,datestr,datestr,datestr,"");
	else
		str.Format(temp,datestr,datestr,datestr,datestr,datestr,where);
	//*/
	dataset.Open(str,adLockUnspecified);
	for (int i = 0; i < dataset.GetRecordCount() ; i++)
	{
		int n = 0;
		m_list.InsertItem(i,"");
		m_list.SetItemText(i,n++,(_bstr_t)dataset.GetFields()->Item["emp_name"]->Value);
		m_list.SetItemText(i,n++,(_bstr_t)dataset.GetFields()->Item["workday"]->Value);
		m_list.SetItemText(i,n++,(_bstr_t)dataset.GetFields()->Item["lateday"]->Value);
		m_list.SetItemText(i,n++,(_bstr_t)dataset.GetFields()->Item["leaveearlyday"]->Value);
		m_list.SetItemText(i,n++,(_bstr_t)dataset.GetFields()->Item["bjday"]->Value);
		m_list.SetItemText(i,n++,(_bstr_t)dataset.GetFields()->Item["sjday"]->Value);
		dataset.Next();	
	}//*/
}

void CCheckSum::OnCloseupCemp() 
{
	UpdateList();	
}

void CCheckSum::OnCloseupCyy() 
{
	UpdateList();	
}

void CCheckSum::OnCloseupCmm() 
{
	UpdateList();	
}
