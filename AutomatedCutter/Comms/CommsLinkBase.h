#pragma once
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the COMMS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// COMMS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef COMMS_EXPORTS
#define COMMS_API __declspec(dllexport)
#else
#define COMMS_API __declspec(dllimport)
#endif

#include "GenericBase.h"
#include "Packet.h"
#include "ICommsListener.h"

class COMMS_API CommsLinkBase : GenericBase
{
public:


	virtual void OpenConnection() = 0;

	virtual void SendData(Packet& pPacket) = 0;

	void AddReceivedDataListener(ICommsListener* pCommsListener);

protected:
	
	void FireReceivedDataEvent(Packet& p);

private:

	vector<ICommsListener *> _receivedDataListeners;
};

