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
#include <iostream>
using namespace std;
class COMMON_API AutoCutterException : public std::exception
{
public:
	AutoCutterException(void);
	AutoCutterException(const string& pMessage);
	AutoCutterException(const char* pMessage);
	string& toString();
	~AutoCutterException(void);

	virtual const char* what() const throw() {
		return _message.c_str();
	}

private:
	string _message;
};

