#include "PortSerializerWin32.h"

namespace AudioMix
{
	// Public methods start.
	PortSerializerWin32::PortSerializerWin32(std::string portName, std::shared_ptr<ILogger> logger)
	{
		_isConnected = false;
		_portName = portName;
		CreatePortFile();
		SetPortParameters();

		_logger = logger;
	}

	PortSerializerWin32::~PortSerializerWin32()
	{
		_isConnected = false;
		CloseHandle(_portDescriptor);
	}

	std::string PortSerializerWin32::ReadData()
	{
		auto resultMessage = std::string();
		uint8_t readableByte = 0;
		DWORD readedByte = 0;

		while (true)
		{
			ReadFile(_portDescriptor, &readableByte, 1, &readedByte, NULL);

			if (readableByte == (uint8_t)StopSymbol)
			{
				break;
			}

			resultMessage.push_back((char)readableByte);
		}
		
		return resultMessage;
	}

	bool PortSerializerWin32::GetIsConnected()
	{
		return _isConnected;
	}

	std::string PortSerializerWin32::GetPortName()
	{
		return _portName;
	}
	// Public methods end.

	// Private mathods start.
	void PortSerializerWin32::CreatePortFile()
	{
		_portDescriptor = CreateFile(_portName.c_str(),
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

	void PortSerializerWin32::SetPortParameters()
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
	// Private methods end.
}