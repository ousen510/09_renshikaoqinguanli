#if !defined(AFX_CHECKSUM_H__6B0EAB6F_6796_4737_859B_01B7C517F757__INCLUDED_)
#define AFX_CHECKSUM_H__6B0EAB6F_6796_4737_859B_01B7C517F757__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CheckSum.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCheckSum dialog

class CCheckSum : public CDialog
{
// Construction
public:
	CCheckSum(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCheckSum)
	enum { IDD = IDD_DLGCHECKSUM };
	CListCtrl	m_list;
	CComboBox	m_cyy;
	CComboBox	m_cmm;
	CComboBox	m_cemp;
	CString	m_emp;
	CString	m_mm;
	CString	m_yy;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCheckSum)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCheckSum)
	virtual BOOL OnInitDialog();
	afx_msg void OnCloseupCemp();
	afx_msg void OnCloseupCyy();
	afx_msg void OnCloseupCmm();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void UpdateList();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHECKSUM_H__6B0EAB6F_6796_4737_859B_01B7C517F757__INCLUDED_)
