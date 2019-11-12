#if !defined(AFX_DEPTEDIT_H__E65C7EEB_B07B_473D_B22E_44F278C70204__INCLUDED_)
#define AFX_DEPTEDIT_H__E65C7EEB_B07B_473D_B22E_44F278C70204__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeptEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDeptEdit dialog

class CDeptEdit : public CDialog
{
// Construction
public:
	CString memo;
	CString name;
	BOOL isroot;
	BOOL visible;
	CDeptEdit(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDeptEdit)
	enum { IDD = IDD_DLGDEPTEDIT };
	CEdit	m_name;
	CEdit	m_memo;
	CButton	m_root;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeptEdit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDeptEdit)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEPTEDIT_H__E65C7EEB_B07B_473D_B22E_44F278C70204__INCLUDED_)
