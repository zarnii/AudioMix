#pragma once
#include <stdexcept>

namespace AudioMix
{
	namespace Exceptions
	{
		/// <summary>
		/// Ошибка создания файла.
		/// </summary>
		class CreateFileException: public std::exception
		{
		public:
			CreateFileException(const char* message)
				: exception(message) {}

			CreateFileException()
				: exception() {}
		};
	}
}