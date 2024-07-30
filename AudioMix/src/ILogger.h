#pragma once
#include <string>
#include "NameOf.h"

namespace AudioMix
{
	/// <summary>
	/// ������.
	/// </summary>
	class ILogger
	{
	public:
		/// <summary>
		/// ����������� ����������.
		/// </summary>
		/// <param name="info">����������.</param>
		virtual void LogInforamtion(const std::string& info) = 0;

		/// <summary>
		/// ����������� ������.
		/// </summary>
		/// <param name="error">������.</param>
		virtual void LogError(const std::string& error) = 0;
	};
}