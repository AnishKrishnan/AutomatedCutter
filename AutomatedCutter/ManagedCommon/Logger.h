#pragma once
#include <stdarg.h>
#include <ctime>
#include "AutoCutterException.h"

using namespace System;
namespace ManagedCommon
{
public ref class Logger
{

public:
	static Logger^ Instance();
	static void Create(String^ pFilePath, bool pTrace);


	void Log(String^ pMessage, ...array<Object^> ^ pArgs);

	void LogError(String^ pMessage, ...array<Object^> ^ pArgs);

	~Logger(void);

private:
	String^ _filePath;
	bool _fullTrace;
	IO::StreamWriter^ _logFile;
	Text::StringBuilder _stringBuilder;
	static const int MAX_LOGSIZE = 1000;

	literal String^ LOGFILE_PREFIX = "Log_";
	literal String^ LOGFILE_SUFFIX = "_txt";

	static Logger^ _logger;

	Logger(String^ pFilePath, bool pTrace);
};
}

