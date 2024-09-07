#pragma once
#include <string>

namespace AudioMix
{
	/// <summary>
	/// Интерфейс сериалайзера последовательного порта.
	/// </summary>
	class IPlatformPortSerializer
	{
	public:
		/// <summary>
		/// Чтение данных из порта. Останавливающая операция.
		/// </summary>
		/// <returns>Данные в виде строки.</returns>
		virtual std::string ReadData() = 0;

		/// <summary>
		/// Получение флага, показывающего подключен ли порт.
		/// </summary>
		/// <returns>True, если порт подключен.</returns>
		virtual bool GetIsConnected() = 0;

		/// <summary>
		/// Получение имени порта.
		/// </summary>
		/// <returns>Имя порта. </returns>
		virtual std::string GetPortName() = 0;

		/// <summary>
		/// Десктруктор.
		/// </summary>
		virtual ~IPlatformPortSerializer() = default;
	};
}