#include "ProcessHandler.h"

namespace AudioMix
{

	std::wstring ProcessHandler::GetProcessNameByPid(DWORD pid)
	{
		if (pid == (DWORD)SystemPid)
		{
			return std::wstring(L"system");
		}

		auto hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, false, pid);

		
		if (!hProcess)
		{
			throw Exceptions::OpenProcessException(
				std::format("Open process error (pid: {}).", pid).c_str());
		}
		

		const DWORD bufferSize = 1024;
		wchar_t buffer[bufferSize];
		auto result = QueryFullProcessImageNameW(
			hProcess, 
			PROCESS_NAME_NATIVE, 
			buffer, 
			const_cast<PDWORD>(&bufferSize)
		);
		CloseHandle(hProcess);

		
		if (!result)
		{
			throw Exceptions::GetProcessNameException(
				std::format("Get process name error (pid: {}).", pid).c_str());
		}
		
		auto processName = std::wstring(buffer);

		return GetRightSubstring(processName);
	}

	std::wstring ProcessHandler::GetRightSubstring(std::wstring& processName)
	{
		auto slashPosition = processName.rfind('\\');

		return processName.substr(slashPosition + 1, processName.length() - slashPosition);
	}
}