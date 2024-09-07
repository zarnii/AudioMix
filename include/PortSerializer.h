#pragma once
#include <memory>
#include "IPlatformPortSerializer.h"
#include "ILogger.h"

namespace AudioMix
{
	/// <summary>
	/// Прокси объектов PortSerializerWin32 и PortSerializerLinux.
	/// </summary>
	class PortSerializer
	{
	private:
		std::unique_ptr<IPlatformPortSerializer> _ppSerializer;
	public:
		/// <summary>
		/// Конструктор.
		/// </summary>
		/// <param name="portName">Имя порта.</param>
		/// <param name="logger">Логгер.</param>
		PortSerializer(std::string portName, std::shared_ptr<ILogger> logger);
		
		/// <summary>
		/// Конструктор перемещения.
		/// </summary>
		/// <param name="right"></param>
		PortSerializer(PortSerializer&& right) noexcept;

		PortSerializer(const PortSerializer& other) = delete;

		/// <summary>
		/// Чтение данных с порта, останавливающая операция.
		/// </summary>
		/// <returns>Считанные данные.</returns>
		std::string ReadData();

		/// <summary>
		/// Получение флага, показывающего подключен ли порт.
		/// </summary>
		/// <returns>True, если да.</returns>
		bool GetIsConnected();

		/// <summary>
		/// Получение имени порта.
		/// </summary>
		/// <returns>Имя порта.</returns>
		std::string GetPortName();
	};
}