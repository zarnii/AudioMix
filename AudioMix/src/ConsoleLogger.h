#pragma once
#include "ILogger.h"
#include <iostream>
#include <chrono>
#include <format>

namespace AudioMix
{
	/// <summary>
	/// ���������� ������.
	/// </summary>
	class ConsoleLogger : public ILogger
	{
	private:
		/// <summary>
		/// ��������� �������� ������� � ���� ������.
		/// </summary>
		/// <returns>������ ������� Y-m-d H:M:S.</returns>
		std::string GetCurentTimeFormatString();

	public:
		/// <summary>
		/// ����������� ����������.
		/// </summary>
		/// <param name="info">����������.</param>
		void LogInforamtion(const std::string& info) override;

		/// <summary>
		/// ����������� ������.
		/// </summary>
		/// <param name="error">������.</param>
		void LogError(const std::string& error) override;
	};
}