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
#include <string>
#include <sstream>
#include <fstream>
#include <stdarg.h>
#include <ctime>
#include "AutoCutterException.h"

using namespace std;
class COMMON_API Logger
{

public:
	static Logger* instance();
	static void create(string& pFilePath, bool pTrace);


	void Log(string& pMessage, ...);

	void LogError(string& pMessage, ...);

	void writeLog();
	~Logger(void);

private:
	string _filePath;
	bool _fullTrace;
	ofstream _logFile;
	stringstream _stringBuilder;
	static const int MAX_LOGSIZE = 1000;

	static const string LOGFILE_PREFIX;
	static const string LOGFILE_SUFFIX;

	static Logger* _logger;

	Logger(string& pFilePath, bool pTrace);
	Logger(void);
	Logger& operator=(Logger const&);
};

