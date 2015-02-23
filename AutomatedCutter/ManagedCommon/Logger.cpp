#include "stdafx.h"
#include "Logger.h"

ManagedCommon::Logger::Logger(String^ pFilePath, bool pTrace)
{
	if(pFilePath == nullptr)
	{

	}
	_fullTrace = pTrace;
	time_t t = time(0);
	struct tm now;
	localtime_s(&now, &t);
	Text::StringBuilder filePathBuilder;
	filePathBuilder.Append(pFilePath + LOGFILE_PREFIX + now.tm_year + "_" + now.tm_mon + "_" + now.tm_mday + "_" + now.tm_hour + "_" + now.tm_min + "_" + now.tm_sec + LOGFILE_SUFFIX);

	_logFile = gcnew IO::StreamWriter(filePathBuilder.ToString());

	if(_logFile == nullptr)
	{
		throw gcnew AutoCutterException("Could not open log file");
	}
}


void ManagedCommon::Logger::Create(String^ pFilePath, bool pTrace)
{
	if(!_logger)
	{
		_logger = gcnew Logger(pFilePath, pTrace);
	}

}

ManagedCommon::Logger^ ManagedCommon::Logger::Instance()
{
	if(_logger != nullptr)
	{
		return _logger;
	}else
	{
		throw gcnew AutoCutterException("Please instantiate logger using the create() function");
	}

}

ManagedCommon::Logger::~Logger(void)
{
	_logFile->Flush();
	_logFile->Close();
}

void ManagedCommon::Logger::Log(String^ pMessage, ...array<Object ^> ^ pArgs)
{
	if(pMessage == nullptr)
	{
		throw gcnew AutoCutterException("No message provided for logging");
	}
	if(_fullTrace)
	{
		_logFile->WriteLine(String::Format(pMessage, pArgs));
	}
}

void ManagedCommon::Logger::LogError(String^ pMessage, ...array<Object ^> ^ pArgs)
{
	_logFile->WriteLine(String::Format(pMessage, pArgs));
}
