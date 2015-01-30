#include "stdafx.h"
#include "Packet.h"

Packet::Packet(void)
{
	_log->Log(std::string("Packet::ctor - Start"));

	_totalNumberOfBytes = 0;
	_totalDataBytes = 0;
	_packetType = PACKETTYPE_INVALID;
	_data = NULL;
	_log->Log(std::string("Packet::ctor - Finish"));
}

#pragma region Accessors and Mutators

PacketType Packet::GetPacketType()
{
	return _packetType;
}

void Packet::SetPacketType(PacketType  pPacketType)
{
	if(!IS_VALID_PACKET_TYPE(pPacketType))
	{
		throw AutoCutterException("Packet::SetPacketType - not a valid packet type");
	}

	_packetType = pPacketType;
}

char* Packet::GetData()
{
	if(_data == NULL)
	{
		throw AutoCutterException(std::string("Packet::GetData - Packet data is null"));
	}
	return _data;
}

void Packet::SetData(vector<char>& pData)
{
	
	_data = &pData[0];
	_totalDataBytes = pData.size();
}
#pragma endregion

#pragma region Packet Building

char* Packet::ConstructPacket()
{
	_log->Log(std::string("Packet::ConstructPacket - Start"));

	_log->Log(std::string("Creating packet vector from data"));
	vector<char> packet(_data, _data + sizeof(_data) / sizeof(int));

	_log->Log(std::string("Adding packet data size"));
	char* dataSize = CommonHelper::ConvertIntToCharArray(_totalDataBytes, _log);	
	_log->Log(std::string("Packet::ConstructPacket - Finish"));

	return NULL;
}
#pragma endregion
