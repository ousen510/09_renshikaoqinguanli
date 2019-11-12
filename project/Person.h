// Person.h : main header file for the PERSON application
//

#if !defined(AFX_PERSON_H__66A1711D_9886_4BC4_BA8D_CB59F46E347D__INCLUDED_)
#define AFX_PERSON_H__66A1711D_9886_4BC4_BA8D_CB59F46E347D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPersonApp:
// See Person.cpp for the implementation of this class
//

class CPersonApp : public CWinApp
{
public:
	CPersonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPersonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPersonApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PERSON_H__66A1711D_9886_4BC4_BA8D_CB59F46E347D__INCLUDED_)
