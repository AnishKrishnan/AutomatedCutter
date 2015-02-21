#pragma once

#include "CommsLinkBase.h"
#include "SerialCommsLink.h"
#include "GenericBase.h"
#include "ICommsListener.h"

ref class CommsController : ICommsListener
{
#pragma region Public Methods

public:
	CommsController(System::String^ pPortName, Logger* pLog);

	virtual void RecievedDataCallback(Packet& pPacket) override;

#pragma endregion

private: 
#pragma region Private Methods

#pragma endregion

#pragma region Private Members

	CommsLinkBase^ _commsLink;
	Logger* _log;
#pragma endregion
};

