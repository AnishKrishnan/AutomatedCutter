#pragma once
#include "GenericWrapper.h"
#include "ICommsListener.h"
ref class SerialCommsLink 
{
public:
	SerialCommsLink(void);

	System::IO::Ports::SerialPort serial;

	System::Collections::Generic::List<GenericWrapper<ICommsListener> ^> list;
};

