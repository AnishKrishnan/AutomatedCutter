#pragma once

#include "CommsLinkBase.h"
#include "SerialCommsLink.h"
#include "GenericBase.h"
#include "ICommsListener.h"
#include "CustomPoint3d.h"
#include "Packet.h"
#include "GenericWrapper.h"

ref class CommsController : ICommsListener
{
#pragma region Public Methods

public:
	CommsController(Logger* pLog);

	void ConnectToDevice(System::String^ pPortName);

	virtual void RecievedDataCallback(Packet& pPacket) override;

	void AddCoordinate(CustomPoint3d<float>& pStartPoint, CustomPoint3d<float>& pEndPoint);

#pragma endregion

private: 
#pragma region Private Methods

	vector<char> ConvertPointToData(CustomPoint3d<float>& pPoint);

#pragma endregion

#pragma region Private Members

	CommsLinkBase^ _commsLink;
	Logger* _log;
	System::Collections::Generic::List<GenericWrapper<Packet> ^> _packetsToSend;

#pragma endregion
};

