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
	/// Сериалайзер последовательного порта для Windows.
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
		/// Конструктор.
		/// </summary>
		/// <param name="portName">Имя порта.</param>
		/// <param name="logger">Логгер.</param>
		PortSerializerWin32(std::string portName, std::shared_ptr<ILogger> logger);

		/// <summary>
		/// Деструктор.
		/// </summary>
		~PortSerializerWin32();

		/// <summary>
		/// Чтение данных из порта.
		/// </summary>
		/// <returns>Прочитанные данные в виде строки.</returns>
		std::string ReadData() override;

		/// <summary>
		/// Получение флага, показывающего подключен ли порт.
		/// </summary>
		/// <returns>True, если подключен.</returns>
		bool GetIsConnected() override;

		/// <summary>
		/// Получение имени порта.
		/// </summary>
		/// <returns>Имя порта.</returns>
		std::string GetPortName() override;
	};
}