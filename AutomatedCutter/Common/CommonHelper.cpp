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
	if(pLog == NULL)
	{
		throw AutoCutterException("CommonHelper::ConvertIntToCharArray - pLog is null");
	}

	pLog->Log(std::string("CommonHelper::ConvertItToCharArray - Start"));
	
	pLog->Log(std::string("Initialising array and pointer"));
	char intArray[sizeof(int)];
	char* x = (char*)&pInt;

	pLog->Log(std::string("Creating array"));
	for(int i = 0; i < sizeof(int); i++)
	{
		intArray[INT_ARRAY_OFFSET - i] = x[i];
	}
	
	pLog->Log(std::string("CommonHelper::ConvertItToCharArray - Finish"));
	return intArray;
}

int CommonHelper::ConvertCharArrayToInt(char* pCharArray, Logger* pLog)
{
	if(pLog == NULL)
	{
		throw AutoCutterException("CommonHelper::ConvertCharArrayToInt - pLog is null");
	}

	pLog->Log(std::string("CommonHelper::ConvertCharArrayToInt - Start"));
	
	if(pCharArray == NULL)
	{
		throw AutoCutterException("CommonHelper::ConvertCharArrayToInt - pCharArray is null");
	}

	int value;
	char* pointerToInt = (char*)&value;
	for(int i = 0; i < sizeof(int); i++)
	{
		pointerToInt[INT_ARRAY_OFFSET - i] = pCharArray[i];
	}

	pLog->Log(std::string("Value of char array is %i"), value);
	pLog->Log(std::string("CommonHelper::ConvertCharArrayToInt - Finish"));

	return value;
}