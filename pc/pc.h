// pc.h : main header file for the PC application
//

#if !defined(AFX_PC_H__D928A14A_2454_435F_B9B1_81E20497AC9F__INCLUDED_)
#define AFX_PC_H__D928A14A_2454_435F_B9B1_81E20497AC9F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPcApp:
// See pc.cpp for the implementation of this class
//

class CPcApp : public CWinApp
{
public:
	CPcApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPcApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPcApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PC_H__D928A14A_2454_435F_B9B1_81E20497AC9F__INCLUDED_)
