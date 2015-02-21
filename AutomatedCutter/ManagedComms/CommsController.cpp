#include "stdafx.h"
#include "CommsController.h"


CommsController::CommsController(Logger* pLog)
{
	if(pLog == NULL)
	{
		throw AutoCutterException("CommsController::ctor - pLog is null");
	}

	_log = pLog;
	_packetsToSend.Clear();
}

void CommsController::ConnectToDevice(System::String^ pPortName)
{
	_log->Log(std::string("CommsController::ConnectToDevice - Start"));
	if(pPortName == nullptr)
	{
		throw AutoCutterException("CommsController::ctor - pPortName is null");
	}

	_log->Log(std::string("Instantiating comms link"));
	_commsLink = gcnew SerialCommsLink(pPortName);
	_commsLink->AddReceivedDataListener(this);

	_log->Log(std::string("Opening connection"));
	_commsLink->OpenConnection();

	_log->Log(std::string("CommsController::ConnectToDevice - Finish"));
}

void CommsController::AddCoordinate(CustomPoint3d<float>& pStartPoint, CustomPoint3d<float>& pEndPoint)
{
	_log->Log(std::string("CommsController::AddCoordinate - Start"));
	Packet* packetToAdd = new Packet();
	packetToAdd->SetPacketType(PACKETTYPE_PATH_REQUEST);

	vector<char> packetData;

	_log->Log(std::string("Adding start point to packet data"));
	vector<char> startPointData = ConvertPointToData(pStartPoint);
	packetData.insert(packetData.end(), startPointData.begin(), startPointData.end());

	_log->Log(std::string("Adding end point to packet data"));
	vector<char> endPointData = ConvertPointToData(pEndPoint);
	packetData.insert(packetData.end(), endPointData.begin(), endPointData.end());

	packetToAdd->SetData(packetData);

	_log->Log(std::string("Adding packet to list"));
	GenericWrapper<Packet> ^ packetWrapper = gcnew GenericWrapper<Packet>(packetToAdd);
	_packetsToSend.Add(packetWrapper);

	_log->Log(std::string("CommsController::AddCoordinate - Finish"));
}

void CommsController::RecievedDataCallback(Packet& pPacket)
{
	throw AutoCutterException("CommsController::ReceivedDataCallback - Implement me");
}

vector<char> CommsController::ConvertPointToData(CustomPoint3d<float>& pPoint)
{
	_log->Log(std::string("CommsController::ConvertPointToData - Start"));
	vector<char> convertedData;
	char floatData[sizeof(float)];

	_log->Log(std::string("Converting x coordinate"));
	CommonHelper::ConvertValueToCharArray<float>(pPoint.GetX(), floatData, _log);
	convertedData.insert(convertedData.end(), floatData, floatData + sizeof(float));

	_log->Log(std::string("Converting y coordinate"));
	CommonHelper::ConvertValueToCharArray<float>(pPoint.GetY(), floatData, _log);
	convertedData.insert(convertedData.end(), floatData, floatData + sizeof(float));

	_log->Log(std::string("Converting z coordinate"));
	CommonHelper::ConvertValueToCharArray<float>(pPoint.GetZ(), floatData, _log);
	convertedData.insert(convertedData.end(), floatData, floatData + sizeof(float));

	_log->Log(std::string("CommsController::ConvertPointToData - Finish"));
	return convertedData;
}