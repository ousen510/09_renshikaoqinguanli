#if !defined(AFX_PERSONMANAGE_H__0B134AC2_571A_4A81_AAE2_C02063B504B2__INCLUDED_)
#define AFX_PERSONMANAGE_H__0B134AC2_571A_4A81_AAE2_C02063B504B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PersonManage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPersonManage dialog

class CPersonManage : public CDialog
{
// Construction
public:
	int m_DeptID;
	CPersonManage(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPersonManage)
	enum { IDD = IDD_DLGPERSON };
	CListCtrl	m_list;
	CTreeCtrl	m_tree;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPersonManage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPersonManage)
	virtual BOOL OnInitDialog();
	afx_msg void OnAdd();
	afx_msg void OnEdit();
	afx_msg void OnDelete();
	afx_msg void OnSelchangedTreedept(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void UpdatePerson();
	void GetNode(HTREEITEM pNode,int nPid);
	void UpdateDept();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PERSONMANAGE_H__0B134AC2_571A_4A81_AAE2_C02063B504B2__INCLUDED_)
