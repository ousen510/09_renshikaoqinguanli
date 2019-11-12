#if !defined(AFX_PASSWORDEDIT_H__47A914EE_B174_48CB_A9AD_621B385A92FD__INCLUDED_)
#define AFX_PASSWORDEDIT_H__47A914EE_B174_48CB_A9AD_621B385A92FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PassWordEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPassWordEdit dialog

class CPassWordEdit : public CDialog
{
// Construction
public:
	CString PassWord;
	CADODataSet m_DataSet;
	CPassWordEdit(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPassWordEdit)
	enum { IDD = IDD_DLGPASS };
	CEdit	m_password;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPassWordEdit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPassWordEdit)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PASSWORDEDIT_H__47A914EE_B174_48CB_A9AD_621B385A92FD__INCLUDED_)
