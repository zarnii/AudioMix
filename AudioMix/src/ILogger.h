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
		/// <param name="callerName">Имя вызывающего компонента (объекта).</param>
		virtual void LogInforamtion(const std::string& info, const std::string& callerName) = 0;

		/// <summary>
		/// Логирование ошибки.
		/// </summary>
		/// <param name="error">Ошибка.</param>
		/// <param name="callerName">Имя вызывающего компонента (объекта).</param>
		virtual void LogError(const std::string& error, const std::string& callerName) = 0;
	};
}