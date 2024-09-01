#pragma once
#include <stdexcept>

namespace AudioMix
{
	namespace Exceptions
	{
		/// <summary>
		/// ������ ��������� ������������ ����������.
		/// </summary>
		class GetDeviceConfigurationException : public std::exception
		{
		public:
			GetDeviceConfigurationException(const char* message)
				: exception(message) {}
			GetDeviceConfigurationException()
				: exception() {}
		};
	}
}