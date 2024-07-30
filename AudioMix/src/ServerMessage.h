#pragma once
#include <cstdint>

namespace AudioMix
{
	/// <summary>
	/// ��������� �������.
	/// </summary>
	struct ServerMessage
	{
		/// <summary>
		/// ����� ��������.
		/// </summary>
		uint8_t sliderNumber;

		/// <summary>
		/// ��������.
		/// </summary>
		float value;
	};
}