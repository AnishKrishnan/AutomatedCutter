// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the COMMON_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// COMMON_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef COMMON_EXPORTS
#define COMMON_API __declspec(dllexport)
#else
#define COMMON_API __declspec(dllimport)
#endif

#pragma once
#include "Logger.h"

static class COMMON_API CommonHelper 
{
public:
	//CommonHelper(void);
	//~CommonHelper(void);

	static char* ConvertIntToCharArray(int pInt, Logger* pLog);
};

