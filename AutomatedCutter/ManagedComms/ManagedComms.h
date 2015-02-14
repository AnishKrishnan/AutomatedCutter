// ManagedComms.h : main header file for the ManagedComms DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CManagedCommsApp
// See ManagedComms.cpp for the implementation of this class
//

class CManagedCommsApp : public CWinApp
{
public:
	CManagedCommsApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
