#pragma once
#include <iostream>
using namespace System;
namespace ManagedCommon
{
public ref class AutoCutterException : System::Exception
{
public:
	AutoCutterException(void);
	AutoCutterException(String^ pMessage);
	AutoCutterException(String^ pMessage, Exception^ pInner);

};
}
