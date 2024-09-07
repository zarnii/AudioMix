#include "PortSerializer.h"
#if defined (_WIN32)
#include "PortSerializerWin32.h"
#elif defined (__linux__)
#include "PortSerializerLinux.h"
#endif


namespace AudioMix
{
	PortSerializer::PortSerializer(std::string portName, std::shared_ptr<ILogger> logger)
#if defined(_WIN32)
		: _ppSerializer(std::make_unique<PortSerializerWin32>(portName, logger))
#elif defined(__linux__)
		: _ppSerializer(std::make_unique<PortSerializerLinux>(portName, logger))
#endif
	{}

	PortSerializer::PortSerializer(PortSerializer&& right) noexcept
		:	_ppSerializer(std::move(right._ppSerializer))
	{}

	std::string PortSerializer::ReadData()
	{
		return _ppSerializer->ReadData();
	}

	bool PortSerializer::GetIsConnected()
	{
		return _ppSerializer->GetIsConnected();
	}

	std::string PortSerializer::GetPortName()
	{
		return _ppSerializer->GetPortName();
	}
}