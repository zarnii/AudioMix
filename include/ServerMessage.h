#pragma once
#include <cstdint>

namespace AudioMix
{
	/// <summary>
	/// Сообщение сервера.
	/// </summary>
	struct ServerMessage
	{
		/// <summary>
		/// Номер слайдера.
		/// </summary>
		uint8_t sliderNumber;

		/// <summary>
		/// Значение.
		/// </summary>
		float value;
	};
}