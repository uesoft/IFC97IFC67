// IFC97IFC67.h : main header file for the IFC97IFC67 application
//

//************************************************************
//     作    者：                                            *
//              长沙优易软件开发有限公司(UESoft Corp.) 邝祝芳*
//     文件名称：                                            * 
//                                                           *
//     完成时间：                                            *
//                2005年5月                                  *
//************************************************************

#if !defined(AFX_IFC97IFC67_H__D2482D10_F085_430B_92BD_EB81166284FC__INCLUDED_)
#define AFX_IFC97IFC67_H__D2482D10_F085_430B_92BD_EB81166284FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CIFC97IFC67App:
// See IFC97IFC67.cpp for the implementation of this class
//

class CIFC97IFC67App : public CWinApp
{
public:
	CIFC97IFC67App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIFC97IFC67App)
	public:
	virtual BOOL InitInstance();
	virtual void WinHelp(DWORD dwData, UINT nCmd = HELP_CONTEXT);
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CIFC97IFC67App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	afx_msg void OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IFC97IFC67_H__D2482D10_F085_430B_92BD_EB81166284FC__INCLUDED_)
