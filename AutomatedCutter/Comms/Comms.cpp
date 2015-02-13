// Comms.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Comms.h"

// This is the constructor of a class that has been exported.
// see Comms.h for the class definition
Comms::Comms()
{
	return;
}

void Comms::RecievedDataCallback(Packet& p)
{
	throw AutoCutterException("Implement me");
}
