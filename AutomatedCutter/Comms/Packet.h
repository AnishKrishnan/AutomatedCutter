// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the COMMS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// COMMS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef COMMS_EXPORTS
#define COMMS_API __declspec(dllexport)
#else
#define COMMS_API __declspec(dllimport)
#endif


#pragma once
#include "genericbase.h"
#include "CommonHelper.h"
typedef enum 
{
	PACKETTYPE_INVALID = 0,
	PACKETTYPE_ACK,
	PACKETTYPE_NACK,
	PACKETTYPE_PATH_REQUEST,
	PACKETTYPE_PATH_COMPLETED

}PacketType;

#define IS_VALID_PACKET_TYPE(Type) (Type == PACKETTYPE_ACK			|| \
								    Type == PACKETTYPE_NACK			|| \
									Type == PACKETTYPE_PATH_REQUEST || \
									Type == PACKETTYPE_PATH_COMPLETED  \
									)		

static const char PACKET_START_BYTE = 0xFF;
	
static const int PACKET_END_STREAM_LENGTH = 4;
static char PACKET_END_STREAM [] = {0xFF,0xFF,0xFF,0xFF};

class COMMS_API Packet :	public GenericBase
{
public:
	Packet(void);

	char* ConstructPacket(vector<char>& pData);
	char* ConstructPacket();
	bool TryParseDataToPacket(vector<char>& pData);
	
	PacketType GetPacketType();
	void SetPacketType(PacketType pPacketType);

	vector<char>& GetData();
	void SetData(vector<char>& pData);



private:


	int _totalNumberOfBytes;

	PacketType _packetType;

	int _totalDataBytes;

	vector<char> _data, _fullPacketData;
};

