#include "stdafx.h"
#include "CommsController.h"


CommsController::CommsController(System::String^ pPortName, Logger* pLog)
{
	if(pLog == NULL)
	{
		throw AutoCutterException("CommsController::ctor - pLog is null");
	}
	if(pPortName == nullptr)
	{
		throw AutoCutterException("CommsController::ctor - pPortName is null");
	}
	
	_log = pLog;

	_commsLink = gcnew SerialCommsLink(pPortName);
	_commsLink->AddReceivedDataListener(this);
	
}

void CommsController::RecievedDataCallback(Packet& pPacket)
{
	throw AutoCutterException("CommsController::ReceivedDataCallback - Implement me");
}
