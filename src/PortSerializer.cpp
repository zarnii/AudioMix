#include "PortSerializer.h"

namespace AudioMix
{
	PortSerializer::PortSerializer(std::string portName, std::shared_ptr<ILogger> logger)
	{
		_isConnected = false;
		_portName = portName;
		CreatePortFile();

		_logger = logger;
	}

	PortSerializer::~PortSerializer()
	{
		_isConnected = false;
		CloseHandle(_portDescriptor);
	}

	std::vector<uint8_t> PortSerializer::ReadData()
	{
		
		return std::vector<uint8_t>();
	}

	void PortSerializer::CreatePortFile()
	{
		auto _portDescriptor = CreateFileA(_portName.c_str(),
			GENERIC_READ,
			0,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL);

		if (_portDescriptor == INVALID_HANDLE_VALUE)
		{
			throw Exceptions::CreateFileException("Create port file error (INVALID_HANDLE_VALUE)");
		}
	}

	void PortSerializer::SetPortParameters()
	{
		DCB dcb;
		
		if (!GetCommState(_portDescriptor, &dcb))
		{
			throw Exceptions::GetDeviceConfigurationException("Failed to get serial port configuration");
		}

		dcb.BaudRate = CBR_9600;
		dcb.ByteSize = DefaultByteSize;
		dcb.Parity = NOPARITY;
		dcb.StopBits = ONE5STOPBITS;

		if (!SetCommState(_portDescriptor, &dcb))
		{
			throw Exceptions::SetDeviceConfigurationException("Failed to set serial port configuration");
		}

		_isConnected = true;
	}
}