#include "stdafx.h"
#include "SerialCommsLink.h"


SerialCommsLink::SerialCommsLink(void) : CommsLinkBase()
{
	_serialPort = gcnew System::IO::Ports::SerialPort();

	throw AutoCutterException("Implement me");
}

void SerialCommsLink::OpenConnection()
{
	throw AutoCutterException("Implement me");
}

void SerialCommsLink::SendData(Packet& pPacket)
{
	throw AutoCutterException("Implement me");
}

void SerialCommsLink::CloseConnection()
{
	throw AutoCutterException("Implement me");
}

void SerialCommsLink::ReceiveByte(char pByte)
{
	throw AutoCutterException("Implement me");
}
