#include "stdafx.h"
#include "AutoCutterException.h"


ManagedCommon::AutoCutterException::AutoCutterException(void) : Exception()
{
}

ManagedCommon::AutoCutterException::AutoCutterException(String^ pMessage) : Exception(pMessage)
{
	
}

ManagedCommon::AutoCutterException::AutoCutterException(String^ pMessage, Exception^ pInner): Exception(pMessage, pInner)
{

}

