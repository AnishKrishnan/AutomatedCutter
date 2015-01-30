#include "stdafx.h"
#include "CommonHelper.h"


//CommonHelper::CommonHelper(void)
//{
//}
//
//
//CommonHelper::~CommonHelper(void)
//{
//}

char* CommonHelper::ConvertIntToCharArray(int pInt, Logger* pLog)
{
	pLog->Log(std::string("CommonHelper::ConvertItToCharArray - Start"));
	
	pLog->Log(std::string("Initialising array and pointer"));
	char intArray[sizeof(int)];
	char* x = (char*)&pInt;

	pLog->Log(std::string("Creating array"));
	for(int i = 0; i < sizeof(int); i++)
	{
		intArray[3 - i] = x[i];
	}
	
	pLog->Log(std::string("CommonHelper::ConvertItToCharArray - Finish"));
	return intArray;
}