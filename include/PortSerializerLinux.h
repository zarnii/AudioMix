#pragma once
#include <memory>
#include "IPlatformPortSerializer.h"
#include "ILogger.h"

namespace AudioMix
{
	/// <summary>
	/// Сериалайзер последовательного порта для Linux.
	/// </summary>
	class PortSerializerLinux: public IPlatformPortSerializer
	{
	private:
		std::string _portName;
		std::shared_ptr<ILogger> _logger;
		bool _isConnected;
	public:
		/// <summary>
		/// Конструктор.
		/// </summary>
		/// <param name="portName">Имя порта.</param>
		/// <param name="logger">Логгер.</param>
		PortSerializerLinux(std::string portName, std::shared_ptr<ILogger> logger);
		
		/// <summary>
		/// Деструктор.
		/// </summary>
		~PortSerializerLinux();

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