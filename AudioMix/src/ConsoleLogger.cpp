#include "ConsoleLogger.h"

namespace AudioMix
{
	void ConsoleLogger::LogInforamtion(const std::string& info)
	{
		
		std::cout << std::format("[INFO {}]: ", GetCurentTimeFormatString()) << info << std::endl;
	}

	void ConsoleLogger::LogError(const std::string& error)
	{
		std::cout << std::format("[ERROR {}]: ", GetCurentTimeFormatString()) << error << std::endl;
	}

	std::string ConsoleLogger::GetCurentTimeFormatString()
	{
		auto now = std::chrono::system_clock::now();
		auto nowTimeT = std::chrono::system_clock::to_time_t(now);
		tm localTime;
		localtime_s(&localTime, &nowTimeT);

		return std::format("{}-{}-{} {}:{}:{}", 
			localTime.tm_year + 1900, // tm_year - год с 1900. 
			localTime.tm_mon + 1, // tm_mon - день с 0 по 11.
			localTime.tm_mday,
			localTime.tm_hour,
			localTime.tm_min,
			localTime.tm_sec);
	}
}