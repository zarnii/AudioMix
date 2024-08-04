#pragma once
#include <stdexcept>

namespace AudioMix
{
	namespace Exceptions
	{
		/// <summary>
		/// Ошибка незапущенной аудио службы Windows.
		/// </summary>
		class AudioServiceNotRunning : public std::exception
		{
		public:
			AudioServiceNotRunning(const char* const message)
				: exception(message) {}

			AudioServiceNotRunning()
				: exception() {}
		};
	}
}