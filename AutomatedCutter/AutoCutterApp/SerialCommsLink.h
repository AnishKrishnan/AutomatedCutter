#pragma once
#include "GenericWrapper.h"
#include "CommsLinkBase.h"
#include "ICommsListener.h"

ref class SerialCommsLink : CommsLinkBase
{
public:
	SerialCommsLink();


private:

	System::IO::Ports::SerialPort serial;

	System::Collections::Generic::List<ICommsListener ^> list;

	
};

