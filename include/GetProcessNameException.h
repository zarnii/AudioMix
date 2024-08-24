#pragma once
#include <stdexcept>

namespace AudioMix
{
	namespace Exceptions
	{
		/// <summary>
		/// Ошибка получения имени процесса.
		/// </summary>
		class GetProcessNameException : public std::exception
		{
		public:
			GetProcessNameException(const char* const message)
				: exception(message) {}

			GetProcessNameException()
				: exception() {}
		};
	}
}