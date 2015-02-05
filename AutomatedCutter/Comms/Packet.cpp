#include "stdafx.h"
#include "Packet.h"

Packet::Packet(void)
{
	_log->Log(std::string("Packet::ctor - Start"));

	_totalNumberOfBytes = 0;
	_totalDataBytes = 0;
	_packetType = PACKETTYPE_INVALID;
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

vector<char>& Packet::GetData()
{
	return _data;
}

void Packet::SetData(vector<char>& pData)
{
	
	_data = pData;
	_totalDataBytes = pData.size();
}
#pragma endregion

#pragma region Packet Building

char* Packet::ConstructPacket()
{
	_log->Log(std::string("Packet::ConstructPacket - Start"));

	_log->Log(std::string("Creating packet vector from data"));
	vector<char> packet(_data);

	_log->Log(std::string("Adding packet data size"));
	char* dataSize = CommonHelper::ConvertIntToCharArray(_totalDataBytes, _log);
	if(dataSize == NULL)
	{
		throw AutoCutterException(std::string("Could not retrieve data size"));
	}

	packet.insert(packet.begin(), dataSize, dataSize + sizeof(dataSize) / sizeof(int));

	_log->Log(std::string("Adding packet type"));
	char packetTypeByte = (char)_packetType;
	packet.insert(packet.begin(), packetTypeByte);

	_log->Log(std::string("Adding total packet size"));
	_totalNumberOfBytes = packet.size();

	char* packetSize = CommonHelper::ConvertIntToCharArray(_totalNumberOfBytes, _log);
	if(packetSize == NULL)
	{
		throw AutoCutterException("Could not retrieve total packet size");
	}
	packet.insert(packet.begin(), packetSize, packetSize + sizeof(packetSize) / sizeof(int));

	_log->Log(std::string("Adding start byte"));
	packet.insert(packet.begin(), START_BYTE);

	_log->Log(std::string("Packet::ConstructPacket - Finish"));

	return &packet[0];
}

char* Packet::ConstructPacket(vector<char>& pData)
{
	_log->Log(std::string("Packet::ConstructPacket(vector<char>& pData) - Start"));

	_log->Log(std::string("Setting packet data"));
	SetData(pData);

	_log->Log(std::string("Constructing packet"));
	char* packet = ConstructPacket();
	_log->Log(std::string("Packet::ConstructPacket(vector<char>& pData) - Finish"));

	return packet;
}
#pragma endregion

#pragma region Parsing Raw Data to Packet

bool Packet::TryParseDataToPacket(vector<char>& pData)
{
	_log->Log(std::string("Packet::TryParseDataToPacket - Start"));
	
	int numberOfBytesProcessed = 0, numberOfDataBytes = 0;

	vector<char>::iterator iterator = pData.begin();
	
	_log->Log(std::string("Parsing start byte"));
	if(*iterator++ != START_BYTE)
	{
		_log->Log(std::string("First byte was not start byte. Will not proceed"));
		return false;
	}

	_log->Log(std::string("Parsing number of bytes in packet"));
	_totalNumberOfBytes = CommonHelper::ConvertCharArrayToInt(&(*iterator), _log);
	if(_totalNumberOfBytes <= 0)
	{
		_log->Log(std::string("Number of bytes is less than or equal to 0"));
		return false;
	}
	iterator += sizeof(int);

	_log->Log(std::string("Parsing packet type"));
	_packetType = static_cast<PacketType>(CommonHelper::ConvertCharArrayToInt(&(*iterator),_log));
	if(!IS_VALID_PACKET_TYPE(_packetType))
	{
		_log->Log(std::string("Packet type not part of valid list"));
		return false;
	}
	iterator+= sizeof(int);
	numberOfBytesProcessed += sizeof(int);

	_log->Log(std::string("Parsing number of data bytes"));
	_totalDataBytes = CommonHelper::ConvertCharArrayToInt(&(*iterator), _log);
	if(_totalDataBytes <= 0)
	{
		_log->Log(std::string("Number of data bytes is less than or equal to 0"));
	}
	iterator += sizeof(int);
	numberOfBytesProcessed += sizeof(int);

	_log->Log(std::string("Packet::TryParseDataToPacket - Finish"));
	return true;
}

#pragma endregion
