#pragma once
#include <windows.h>
#include <string>
#include <stdint.h>
#include <vector>
#include <memory>
#include "Exceptions.h"
#include "ILogger.h"
#include "IPlatformPortSerializer.h"

namespace AudioMix
{
	/// <summary>
	/// ����������� ����������������� ����� ��� Windows.
	/// </summary>
	class PortSerializerWin32: public IPlatformPortSerializer
	{
	private:
		const char StopSymbol = '$';
		const uint8_t DefaultByteSize = 8;
		std::shared_ptr<ILogger> _logger;
		HANDLE _portDescriptor;
		std::string _portName;
		bool _isConnected;
		void CreatePortFile();
		void SetPortParameters();

	public:
		/// <summary>
		/// �����������.
		/// </summary>
		/// <param name="portName">��� �����.</param>
		/// <param name="logger">������.</param>
		PortSerializerWin32(std::string portName, std::shared_ptr<ILogger> logger);

		/// <summary>
		/// ����������.
		/// </summary>
		~PortSerializerWin32();

		/// <summary>
		/// ������ ������ �� �����.
		/// </summary>
		/// <returns>����������� ������ � ���� ������.</returns>
		std::string ReadData() override;

		/// <summary>
		/// ��������� �����, ������������� ��������� �� ����.
		/// </summary>
		/// <returns>True, ���� ���������.</returns>
		bool GetIsConnected() override;

		/// <summary>
		/// ��������� ����� �����.
		/// </summary>
		/// <returns>��� �����.</returns>
		std::string GetPortName() override;
	};
}