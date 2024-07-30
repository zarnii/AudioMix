#pragma once
#include <stdexcept>

namespace AudioMix
{
	namespace Exceptions
	{
		class GetProcessNameException : public std::exception
		{
		public:
			GetProcessNameException(const char* const message)
				: exception(message) {}
		};
	}
}