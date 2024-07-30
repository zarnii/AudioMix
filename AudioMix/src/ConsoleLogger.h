#pragma once
#include "ILogger.h"
#include <iostream>
#include <chrono>
#include <format>

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
		void LogInforamtion(const std::string& info) override;

		/// <summary>
		/// Логирование ошибки.
		/// </summary>
		/// <param name="error">Ошибка.</param>
		void LogError(const std::string& error) override;
	};
}