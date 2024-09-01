#pragma once
#include <windows.h>
#include <string>
#include <stdint.h>
#include <vector>
#include <memory>
#include "Exceptions.h"
#include "ILogger.h"

namespace AudioMix
{
	class PortSerializer
	{
	private:
		const uint8_t DefaultByteSize = 8;
		std::shared_ptr<ILogger> _logger;
		HANDLE _portDescriptor;
		std::string _portName;
		bool _isConnected;
		void CreatePortFile();
		void SetPortParameters();

	public:
		PortSerializer(std::string portName, std::shared_ptr<ILogger> logger);
		~PortSerializer();
		std::vector<uint8_t> ReadData();
	};
}