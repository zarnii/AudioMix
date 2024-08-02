#pragma once
#include "ILogger.h"
#include <iostream>
#include <chrono>
#include <format>
#include <iomanip>

namespace AudioMix
{
	/// <summary>
	/// Консольный логгер.
	/// </summary>
	class ConsoleLogger : public ILogger
	{
	private:
		/// <summary>
		/// Получение текущего времени в виде строки.
		/// </summary>
		/// <returns>Строка формата Y-m-d H:M:S.</returns>
		std::string GetCurentTimeFormatString();

	public:
		/// <summary>
		/// Логирование информации.
		/// </summary>
		/// <param name="info">Информация.</param>
		/// <param name="callerName">Имя вызывающего компонента (объекта).</param>
		void LogInforamtion(const std::string& info, const std::string& callerName) override;

		/// <summary>
		/// Логирование ошибки.
		/// </summary>
		/// <param name="error">Ошибка.</param>
		/// <param name="callerName">Имя вызывающего компонента (объекта).</param>
		void LogError(const std::string& error, const std::string& callerName) override;
	};
}