#pragma once
#include <string>
#include "NameOf.h"

namespace AudioMix
{
	/// <summary>
	/// Логгер.
	/// </summary>
	class ILogger
	{
	public:
		/// <summary>
		/// Логирование информации.
		/// </summary>
		/// <param name="info">Информация.</param>
		virtual void LogInforamtion(const std::string& info) = 0;

		/// <summary>
		/// Логирование ошибки.
		/// </summary>
		/// <param name="error">Ошибка.</param>
		virtual void LogError(const std::string& error) = 0;
	};
}