#if !defined(AFX_PERSONEDIT_H__92836559_9AFE_4106_84F9_0F0882B3D334__INCLUDED_)
#define AFX_PERSONEDIT_H__92836559_9AFE_4106_84F9_0F0882B3D334__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PersonEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPersonEdit dialog

class CPersonEdit : public CDialog
{
// Construction
public:
	CPersonEdit(CWnd* pParent = NULL);   // standard constructor
	long m_DeptData;
// Dialog Data
	//{{AFX_DATA(CPersonEdit)
	enum { IDD = IDD_DLGPERSONEDIT };
	CComboBox	m_CombDept;
	CComboBox	m_CombMarital;
	CComboBox	m_CombSex;
	CString	m_id;
	CString	m_marital;
	CString	m_sex;
	CTime	m_birth;
	CTime	m_hire;
	CString	m_card;
	CString	m_culture;
	CString	m_duty;
	CString	m_family;
	CString	m_farty;
	CString	m_files;
	CString	m_hukou;
	CString	m_memo;
	CString	m_mobile;
	CString	m_name;
	CString	m_nationality;
	CString	m_office;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPersonEdit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPersonEdit)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PERSONEDIT_H__92836559_9AFE_4106_84F9_0F0882B3D334__INCLUDED_)
