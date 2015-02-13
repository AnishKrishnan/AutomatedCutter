#pragma once
#include "GenericBase.h"
#include "Packet.h"

class ICommsListener :	public GenericBase
{
public:

	virtual void RecievedDataCallback(Packet& pPacket) = 0;
};

