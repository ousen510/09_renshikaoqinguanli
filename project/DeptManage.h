#if !defined(AFX_DEPTMANAGE_H__8D2D9BAB_5D00_4418_8ED7_A603867E6985__INCLUDED_)
#define AFX_DEPTMANAGE_H__8D2D9BAB_5D00_4418_8ED7_A603867E6985__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeptManage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDeptManage dialog

class CDeptManage : public CDialog
{
// Construction
private:
	void GetNode(HTREEITEM node,int nPid);
	void UpdateDept();
public:
	CADODataSet m_DataSet;
	CDeptManage(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDeptManage)
	enum { IDD = IDD_DLGDEPT };
	CTreeCtrl	m_tree;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeptManage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDeptManage)
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd();
	afx_msg void OnEdit();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEPTMANAGE_H__8D2D9BAB_5D00_4418_8ED7_A603867E6985__INCLUDED_)
