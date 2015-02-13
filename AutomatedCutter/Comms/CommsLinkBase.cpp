#include "stdafx.h"
#include "CommsLinkBase.h"


void CommsLinkBase::AddReceivedDataListener(ICommsListener* pCommsListener)
{
	_log->Log(std::string("CommsLinkBase::AddReceivedDataListener - Start"));
	if(pCommsListener == NULL)
	{
		throw AutoCutterException("CommsLinkBase::AddReceivedDataListener - pCommsListener is null");
	}

	_log->Log(std::string("Adding pCommsListener to list"));

	_receivedDataListeners.push_back(pCommsListener);

	_log->Log(std::string("CommsLinkBase::AddReceivedDataListener - Finish"));
}
void CommsLinkBase::FireReceivedDataEvent(Packet& pPacket)
{
	_log->Log(std::string("CommsLinkBase::FireReceivedDataEvent - Start"));

	_log->Log(std::string("Firing received data event on %i listeners"), _receivedDataListeners.size());

	for(int i = 0; i < _receivedDataListeners.size(); i++)
	{
		_receivedDataListeners.at(i)->RecievedDataCallback(pPacket);
	}

	_log->Log(std::string("CommsLinkBase::FireReceivedDataEvent - Finish"));
}