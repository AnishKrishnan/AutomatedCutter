#include "stdafx.h"
#include "CommsController.h"


CommsController::CommsController(Logger* pLog)
{
	if(pLog == NULL)
	{
		throw AutoCutterException("CommsController::ctor - pLog is null");
	}

	_log = pLog;
}

void CommsController::ConnectToDevice(System::String^ pPortName)
{
	_log->Log(std::string("CommsController::ConnectToDevice - Start"));
	if(pPortName == nullptr)
	{
		throw AutoCutterException("CommsController::ctor - pPortName is null");
	}

	_log->Log(std::string("Instantiating comms link"));
	_commsLink = gcnew SerialCommsLink(pPortName);
	_commsLink->AddReceivedDataListener(this);

	_log->Log(std::string("Opening connection"));
	_commsLink->OpenConnection();

	_log->Log(std::string("CommsController::ConnectToDevice - Finish"));
}


void CommsController::RecievedDataCallback(Packet& pPacket)
{
	throw AutoCutterException("CommsController::ReceivedDataCallback - Implement me");
}
