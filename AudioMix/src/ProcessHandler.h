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
		/// Pid �������.
		/// </summary>
		static const uint8_t SystemPid = 0;

		/// <summary>
		/// ��������� ������ ��������� ����� �������� �� ����� "\".
		/// </summary>
		/// <param name="processName">������ ��� ��������.</param>
		/// <returns>������ ���������.</returns>
		static std::wstring GetRightSubstring(std::wstring& processName);
	public:
		/// <summary>
		/// ��������� ����� �������� ���� "Process.exe"
		/// Exceptions:
		/// AudioMix::Exceptions::OpenProcessException - ������ �������� �������� ��������.
		/// AudioMix::Exceptions::GetProcessNameException - ������ ��������� ����� ��������.
		/// </summary>
		/// <param name="pid">Id ��������.</param>
		/// <returns>��� ��������.</returns>
		static std::wstring GetProcessNameByPid(DWORD pid);
	};
}