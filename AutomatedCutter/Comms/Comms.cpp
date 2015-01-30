// Comms.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Comms.h"


// This is an example of an exported variable
COMMS_API int nComms=0;

// This is an example of an exported function.
COMMS_API int fnComms(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see Comms.h for the class definition
CComms::CComms()
{
	return;
}
