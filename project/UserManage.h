#if !defined(AFX_USERMANAGE_H__90C51823_0694_4F22_9F74_0461C026F3E7__INCLUDED_)
#define AFX_USERMANAGE_H__90C51823_0694_4F22_9F74_0461C026F3E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserManage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserManage dialog

class CUserManage : public CDialog
{
// Construction
public:
	CADODataSet m_DataSet;
	CUserManage(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUserManage)
	enum { IDD = IDD_DLGUSER };
	CListCtrl	m_grid;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserManage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserManage)
	virtual BOOL OnInitDialog();
	afx_msg void OnAppend();
	afx_msg void OnEdit();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void UpdateGrid();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERMANAGE_H__90C51823_0694_4F22_9F74_0461C026F3E7__INCLUDED_)
