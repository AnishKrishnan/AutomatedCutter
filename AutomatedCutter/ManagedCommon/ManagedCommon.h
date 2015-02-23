// ManagedCommon.h : main header file for the ManagedCommon DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CManagedCommonApp
// See ManagedCommon.cpp for the implementation of this class
//

class CManagedCommonApp : public CWinApp
{
public:
	CManagedCommonApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
