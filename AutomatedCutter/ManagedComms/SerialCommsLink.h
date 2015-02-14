#pragma once
#include "CommsLinkBase.h"
#include "ICommsListener.h"

ref class SerialCommsLink : CommsLinkBase
{
public:
	SerialCommsLink();

	virtual void OpenConnection() override;

	virtual void CloseConnection() override;

	virtual void SendData(Packet& pPacket) override;

private:

	void ReceiveByte(char data);

	System::IO::Ports::SerialPort^ _serialPort;	
	
};

