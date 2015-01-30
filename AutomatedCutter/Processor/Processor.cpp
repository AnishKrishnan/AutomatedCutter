// Processor.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Processor.h"


// This is an example of an exported variable
PROCESSOR_API int nProcessor=0;

// This is an example of an exported function.
PROCESSOR_API int fnProcessor(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see Processor.h for the class definition
CProcessor::CProcessor()
{
	return;
}
