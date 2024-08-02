#pragma once
#include "ILogger.h"
#include <iostream>
#include <chrono>
#include <format>
#include <iomanip>

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
		/// <param name="callerName">��� ����������� ���������� (�������).</param>
		void LogInforamtion(const std::string& info, const std::string& callerName) override;

		/// <summary>
		/// ����������� ������.
		/// </summary>
		/// <param name="error">������.</param>
		/// <param name="callerName">��� ����������� ���������� (�������).</param>
		void LogError(const std::string& error, const std::string& callerName) override;
	};
}