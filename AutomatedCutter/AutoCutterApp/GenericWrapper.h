#pragma once
#include "GenericBase.h"
template <typename T> ref class GenericWrapper
{
public:

	GenericWrapper<T>(T* pInternal)
	{
		if(pInternal == NULL)
		{
			throw AutoCutterException("GenericWrapper::ctor - pInternal is null");
		}

		_internal = pInternal;
	}

private:

	T* _internal;
};

