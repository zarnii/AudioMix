#include "PortSerializerLinux.h"

namespace AudioMix
{
	PortSerializerLinux::PortSerializerLinux(std::string portName, std::shared_ptr<ILogger> logger)
	{
		_portName = portName;
		_logger = logger;
	}

	PortSerializerLinux::~PortSerializerLinux()
	{
		// to-do: Close port handle.
	}

	std::string PortSerializerLinux::ReadData()
	{
		return std::string();
	}

	bool PortSerializerLinux::GetIsConnected()
	{
		return _isConnected;
	}

	std::string PortSerializerLinux::GetPortName()
	{
		return _portName;
	}
}