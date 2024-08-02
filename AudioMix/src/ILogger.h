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
		/// <param name="callerName">��� ����������� ���������� (�������).</param>
		virtual void LogInforamtion(const std::string& info, const std::string& callerName) = 0;

		/// <summary>
		/// ����������� ������.
		/// </summary>
		/// <param name="error">������.</param>
		/// <param name="callerName">��� ����������� ���������� (�������).</param>
		virtual void LogError(const std::string& error, const std::string& callerName) = 0;
	};
}