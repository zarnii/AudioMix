#include "ConsoleLogger.h"

namespace AudioMix
{
	void ConsoleLogger::LogInforamtion(const std::string& info, const std::string& callerName)
	{
		
		std::cout << std::format("[INFO]  [{} | {}]: ", callerName, GetCurentTimeFormatString()) << info << std::endl;
	}

	void ConsoleLogger::LogError(const std::string& error, const std::string& callerName)
	{
		std::cout << std::format("[ERROR] [{} | {}]: ", callerName, GetCurentTimeFormatString()) << error << std::endl;
	}

	std::string ConsoleLogger::GetCurentTimeFormatString()
	{
		auto now = std::chrono::system_clock::now();
		auto nowTimeT = std::chrono::system_clock::to_time_t(now);
		tm localTime;
		localtime_s(&localTime, &nowTimeT);

		std::stringstream stringStream;
		stringStream << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");

		return stringStream.str();
	}
}