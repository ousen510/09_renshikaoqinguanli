// PersonDlg.h : header file
//

#if !defined(AFX_PERSONDLG_H__9066E4A1_AB1A_4759_A63D_FB2FBA661A27__INCLUDED_)
#define AFX_PERSONDLG_H__9066E4A1_AB1A_4759_A63D_FB2FBA661A27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPersonDlg dialog

class CPersonDlg : public CDialog
{
// Construction
protected:
	void OnCancel();
public:
	CMenu m_Menu;
	CPersonDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPersonDlg)
	enum { IDD = IDD_PERSON_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPersonDlg)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPersonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMenuuser();
	afx_msg void OnMenupassword();
	afx_msg void OnMenudept();
	afx_msg void OnMenuperson();
	afx_msg void OnMenuexit();
	afx_msg void OnMenucheck();
	afx_msg void OnMenuchecksum();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PERSONDLG_H__9066E4A1_AB1A_4759_A63D_FB2FBA661A27__INCLUDED_)
