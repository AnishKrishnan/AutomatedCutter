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
//
//void CommonHelper::ConvertIntToCharArray(int pInt, char* pIntArray, Logger* pLog)
//{
//	if(pLog == NULL)
//	{
//		throw AutoCutterException("CommonHelper::ConvertIntToCharArray - pLog is null");
//	}
//
//	pLog->Log(std::string("CommonHelper::ConvertItToCharArray - Start"));
//	
//	pLog->Log(std::string("Initialising array and pointer"));
//	
//	char* x = (char*)&pInt;
//
//	pLog->Log(std::string("Creating array"));
//	for(int i = 0; i < sizeof(int); i++)
//	{
//		pIntArray[i] = x[i];
//	}
//	
//	pLog->Log(std::string("CommonHelper::ConvertItToCharArray - Finish"));
//	
//}
//
//int CommonHelper::ConvertCharArrayToInt(char* pCharArray, Logger* pLog)
//{
//	if(pLog == NULL)
//	{
//		throw AutoCutterException("CommonHelper::ConvertCharArrayToInt - pLog is null");
//	}
//
//	pLog->Log(std::string("CommonHelper::ConvertCharArrayToInt - Start"));
//	
//	if(pCharArray == NULL)
//	{
//		throw AutoCutterException("CommonHelper::ConvertCharArrayToInt - pCharArray is null");
//	}
//	
//	int value = 0;
//	char* pointerToInt = (char*)&value;
//	for(int i = 0; i < sizeof(int); i++)
//	{
//		pointerToInt[i] = pCharArray[i];
//	}
//
//	pLog->Log(std::string("Value of char array is %i"), value);
//	pLog->Log(std::string("CommonHelper::ConvertCharArrayToInt - Finish"));
//
//	return value;
//}
