#pragma once
#include <stdexcept>

namespace AudioMix
{
	namespace Exceptions
	{
		class OpenProcessException : public std::exception
		{
		public:
			OpenProcessException(const char* const message)
				: exception(message) {}
		};
	}
}