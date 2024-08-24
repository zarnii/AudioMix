#pragma once
#include <stdexcept>

namespace AudioMix
{
	namespace Exceptions
	{
		/// <summary>
		/// Ошибка конечной аудио точки.
		/// </summary>
		class AudioEndpointException : public std::exception
		{
		public:
			AudioEndpointException(const char* const message)
				: exception(message) {}

			AudioEndpointException()
				:exception() {}
		};
	}
}