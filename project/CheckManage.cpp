// CheckManage.cpp : implementation file
//

#include "stdafx.h"
#include "Person.h"
#include "CheckManage.h"
#include "CheckEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCheckManage dialog


CCheckManage::CCheckManage(CWnd* pParent /*=NULL*/)
	: CDialog(CCheckManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCheckManage)
	m_check = FALSE;
	m_emp = _T("");
	m_mm = _T("");
	m_yy = _T("");
	//}}AFX_DATA_INIT
}


void CCheckManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCheckManage)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBOYY, m_cyy);
	DDX_Control(pDX, IDC_COMBOMM, m_cmm);
	DDX_Control(pDX, IDC_COMBOEMP, m_cemp);
	DDX_Check(pDX, IDC_CHECK1, m_check);
	DDX_CBString(pDX, IDC_COMBOEMP, m_emp);
	DDX_CBString(pDX, IDC_COMBOMM, m_mm);
	DDX_CBString(pDX, IDC_COMBOYY, m_yy);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCheckManage, CDialog)
	//{{AFX_MSG_MAP(CCheckManage)
	ON_BN_CLICKED(IDC_APPEND, OnAdd)
	ON_BN_CLICKED(IDC_EDIT, OnEdit)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_CBN_CLOSEUP(IDC_COMBOYY, OnCloseupComboyy)
	ON_CBN_CLOSEUP(IDC_COMBOMM, OnCloseupCombomm)
	ON_CBN_CLOSEUP(IDC_COMBOEMP, OnCloseupComboemp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCheckManage message handlers

BOOL CCheckManage::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	int i = 0;
	m_list.InsertColumn(i,"人员姓名");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"上班时间");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"下班时间");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"上班考勤时间");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"下班考勤时间");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"请假类别");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"请假起始时间");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"请假结束时间");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"迟到时间");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"早退时间");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"备注");
	m_list.SetColumnWidth(i++,100);

	m_list.InsertColumn(i,"考勤日期");
	m_list.SetColumnWidth(i++,130);

	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	m_check = true;
	this->UpdateData(false);
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

void CCheckManage::UpdateList()
{
	this->UpdateData();
	CString str;
	if (m_check)
		str.Format("Select * From tab_Check");
	else
	{
		CString Starttime,EndTime;
		Starttime = m_yy + "-" + m_mm + "-1" ;
		EndTime.Format("DATEADD(month,1,'%s')",Starttime);
		if (m_emp == "(全部)")
			str.Format("Select * From tab_Check where checkdate between '%s' and %s",Starttime,EndTime);
		else
			str.Format("Select * From tab_Check where name = '%s' and checkdate between '%s' and %s",m_emp,Starttime,EndTime);
	}

	CADODataSet dataset;
	dataset.SetConnection(::GetConnection());
	dataset.Open(str);
	m_list.DeleteAllItems();
	for (int i = 0 ; i < dataset.GetRecordCount() ; i++)
	{	
		int n = 0;
		long data = dataset.GetFields()->Item["autoid"]->Value;
		m_list.InsertItem(i,"");
		m_list.SetItemData(i,data);
		m_list.SetItemText(i,n++,(_bstr_t)dataset.GetFields()->Item["name"]->Value);
		m_list.SetItemText(i,n++,(_bstr_t)dataset.GetFields()->Item["ondutytime"]->Value);
		m_list.SetItemText(i,n++,(_bstr_t)dataset.GetFields()->Item["offdutytime"]->Value);
		m_list.SetItemText(i,n++,(_bstr_t)dataset.GetFields()->Item["ontime"]->Value);
		m_list.SetItemText(i,n++,(_bstr_t)dataset.GetFields()->Item["offtime"]->Value);
		m_list.SetItemText(i,n++,(_bstr_t)dataset.GetFields()->Item["leave"]->Value);
		m_list.SetItemText(i,n++,(_bstr_t)dataset.GetFields()->Item["onleave"]->Value);
		m_list.SetItemText(i,n++,(_bstr_t)dataset.GetFields()->Item["offleave"]->Value);
		m_list.SetItemText(i,n++,(_bstr_t)dataset.GetFields()->Item["latetime"]->Value);
		m_list.SetItemText(i,n++,(_bstr_t)dataset.GetFields()->Item["leaveearly"]->Value);
		m_list.SetItemText(i,n++,(_bstr_t)dataset.GetFields()->Item["memo"]->Value);
		m_list.SetItemText(i,n++,(_bstr_t)dataset.GetFields()->Item["checkdate"]->Value);
		dataset.Next();
	}
}

void CCheckManage::OnAdd() 
{
	CCheckEdit checkedit;
	if (checkedit.DoModal() == IDOK)
	{
		CString time;
		CString str = "Select top 1 * From tab_Check";
		CADODataSet dataset;
		dataset.SetConnection(::GetConnection());
		dataset.Open(str);
		dataset.AddNew();
		dataset.SetFieldValue("name",(_bstr_t)checkedit.m_name);
		dataset.SetFieldValue("checkdate",(_bstr_t)checkedit.m_datecheck.Format("%Y-%m-%d"));
		dataset.SetFieldValue("ondutytime",(_bstr_t)checkedit.m_timeonduty.Format("%H:%M:%S"));
		dataset.SetFieldValue("offdutytime",(_bstr_t)checkedit.m_timeoffduty.Format("%H:%M:%S"));
		dataset.SetFieldValue("ontime",(_bstr_t)checkedit.m_timeon.Format("%H:%M:%S"));
		dataset.SetFieldValue("offtime",(_bstr_t)checkedit.m_timeoff.Format("%H:%M:%S"));
		dataset.SetFieldValue("leave",(_bstr_t)checkedit.m_leave);
		dataset.SetFieldValue("onleave",(_bstr_t)checkedit.m_timeonleave.Format("%H:%M:%S"));
		dataset.SetFieldValue("offleave",(_bstr_t)checkedit.m_timeoffleave.Format("%H:%M:%S"));
		dataset.SetFieldValue("memo",(_bstr_t)checkedit.m_memo);
		CTime latetime = DecTime(checkedit.m_timeon,checkedit.m_timeonduty);
		time.Format("%d:%d:%d",latetime.GetHour(),latetime.GetMinute(),latetime.GetSecond());
		dataset.SetFieldValue("latetime",(_bstr_t)time);
		CTime leaveearly = DecTime(checkedit.m_timeoff,checkedit.m_timeoffduty);
		time.Format("%d:%d:%d",leaveearly.GetHour(),leaveearly.GetMinute(),leaveearly.GetSecond());
		dataset.SetFieldValue("leaveearly",(_bstr_t)time);
		dataset.Save();
		UpdateList();
	}
}

void CCheckManage::OnEdit() 
{
	if (m_list.GetSelectionMark() == -1)
		return;
	int id = m_list.GetItemData(m_list.GetSelectionMark());
	CCheckEdit checkedit;
	CString str;
	str.Format("Select * From tab_Check where autoid = %d",id);
	CADODataSet dataset;
	dataset.SetConnection(::GetConnection());
	dataset.Open(str);
	
	checkedit.m_name = (char *)(_bstr_t)dataset.GetFields()->Item["name"]->Value;
	checkedit.m_timeonduty = GetTimeForStr((char *)(_bstr_t)dataset.GetFields()->Item["ondutytime"]->Value);
	checkedit.m_timeoffduty = GetTimeForStr((char *)(_bstr_t)dataset.GetFields()->Item["offdutytime"]->Value);
	checkedit.m_timeon = GetTimeForStr((char *)(_bstr_t)dataset.GetFields()->Item["ontime"]->Value);
	checkedit.m_timeoff = GetTimeForStr((char *)(_bstr_t)dataset.GetFields()->Item["offtime"]->Value);
	checkedit.m_leave = (char *)(_bstr_t)dataset.GetFields()->Item["leave"]->Value;
	checkedit.m_timeonleave = GetTimeForStr((char *)(_bstr_t)dataset.GetFields()->Item["onleave"]->Value);
	checkedit.m_timeoffleave = GetTimeForStr((char *)(_bstr_t)dataset.GetFields()->Item["offleave"]->Value);
	checkedit.m_memo = (char *)(_bstr_t)dataset.GetFields()->Item["memo"]->Value;
	checkedit.m_datecheck = GetDateForStr((char *)(_bstr_t)dataset.GetFields()->Item["checkdate"]->Value);
	if (checkedit.DoModal() == IDOK)
	{
		CString time;
		dataset.SetFieldValue("name",(_bstr_t)checkedit.m_name);
		dataset.SetFieldValue("checkdate",(_bstr_t)checkedit.m_datecheck.Format("%Y-%m-%d"));
		dataset.SetFieldValue("ondutytime",(_bstr_t)checkedit.m_timeonduty.Format("%H:%M:%S"));
		dataset.SetFieldValue("offdutytime",(_bstr_t)checkedit.m_timeoffduty.Format("%H:%M:%S"));
		dataset.SetFieldValue("ontime",(_bstr_t)checkedit.m_timeon.Format("%H:%M:%S"));
		dataset.SetFieldValue("offtime",(_bstr_t)checkedit.m_timeoff.Format("%H:%M:%S"));
		dataset.SetFieldValue("leave",(_bstr_t)checkedit.m_leave);
		dataset.SetFieldValue("onleave",(_bstr_t)checkedit.m_timeonleave.Format("%H:%M:%S"));
		dataset.SetFieldValue("offleave",(_bstr_t)checkedit.m_timeoffleave.Format("%H:%M:%S"));
		dataset.SetFieldValue("memo",(_bstr_t)checkedit.m_memo);
		CTime latetime = DecTime(checkedit.m_timeon,checkedit.m_timeonduty);
		time.Format("%d:%d:%d",latetime.GetHour(),latetime.GetMinute(),latetime.GetSecond());
		dataset.SetFieldValue("latetime",(_bstr_t)time);
		CTime leaveearly = DecTime(checkedit.m_timeoffduty,checkedit.m_timeoff);
		time.Format("%d:%d:%d",leaveearly.GetHour(),leaveearly.GetMinute(),leaveearly.GetSecond());
		dataset.SetFieldValue("leaveearly",(_bstr_t)time);
		dataset.Save();
		UpdateList();
	}	
}

void CCheckManage::OnDelete() 
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
		str.Format("select * from tab_Check where autoid = %d",id);
		dataset.Open(str);
		dataset.Delete();
		dataset.Save();
		UpdateList();
	}	
}

CTime CCheckManage::DecTime(CTime one, CTime two)
{
	int yy,mm,dd,h,s,m,onetemp,twotemp;
	yy = 2000;//one.GetYear();// - two.GetYear();
	mm = 1;
	dd = 1;
	onetemp = one.GetSecond() + one.GetMinute() * 60 + one.GetHour() * 60 * 60;
	twotemp = two.GetSecond() + two.GetMinute() * 60 + two.GetHour() * 60 * 60;
	if ((onetemp - twotemp) < 0)
	{
		h = m = s = 0;
	}
	else
	{
		h = (onetemp - twotemp) / 60 / 60;
		m = ((onetemp - twotemp) - h * 60 * 60) / 60;
		s = ((onetemp - twotemp) - h * 60 * 60) - m * 60;
	}
	CTime time (yy,mm,dd,h,m,s);
	return time;

}

CTime CCheckManage::GetTimeForStr(CString timestr)
{
	int h,m,s;
	if (timestr.GetLength() < 8)
		timestr = "0"+timestr;
	h = atoi(timestr.Left(2));
	m = atoi(timestr.Mid(3,2));
	s = atoi(timestr.Right(2));
	CTime result(2000,1,1,h,m,s);
	return result;
}

CTime CCheckManage::GetDateForStr(CString datestr)
{
	int y,m,d;
	y = atoi(datestr.Left(4));
	m = atoi(datestr.Mid(5,2));
	d = abs(atoi(datestr.Right(2)));
	CTime result(y,m,d,8,0,0);
	return result;
}

void CCheckManage::OnCheck1() 
{
	UpdateList();	
}



void CCheckManage::OnCloseupComboyy() 
{
	UpdateList();
}

void CCheckManage::OnCloseupCombomm() 
{
	UpdateList();
}

void CCheckManage::OnCloseupComboemp() 
{
	UpdateList();	
}
