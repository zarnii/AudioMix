#pragma once
#include <stdexcept>

namespace AudioMix
{
	namespace Exceptions
	{
		/// <summary>
		/// Ошибка открытия дескриптора процесса.
		/// </summary>
		class OpenProcessException : public std::exception
		{
		public:
			OpenProcessException(const char* const message)
				: exception(message) {}

			OpenProcessException()
				: exception() {}
		};
	}
}