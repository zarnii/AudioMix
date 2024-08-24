#pragma once
#include <string>
#include <windows.h>
#include "Exceptions.h"

namespace AudioMix
{
	class ProcessHandler
	{
	private:
		/// <summary>
		/// Pid системы.
		/// </summary>
		static const uint8_t SystemPid = 0;

		/// <summary>
		/// Получение правой подстроки имени процесса до знака "\".
		/// </summary>
		/// <param name="processName">Полное имя процесса.</param>
		/// <returns>Правая подстрока.</returns>
		static std::wstring GetRightSubstring(std::wstring& processName);
	public:
		/// <summary>
		/// Получение имени процесса вида "Process.exe"
		/// Exceptions:
		/// AudioMix::Exceptions::OpenProcessException - ошибка открытия хэндлера процесса.
		/// AudioMix::Exceptions::GetProcessNameException - ошибка получения имени процесса.
		/// </summary>
		/// <param name="pid">Id процесса.</param>
		/// <returns>Имя процесса.</returns>
		static std::wstring GetProcessNameByPid(DWORD pid);
	};
}