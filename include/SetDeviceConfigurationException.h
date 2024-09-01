#pragma once
#include <exception>

namespace AudioMix
{
	namespace Exceptions
	{
		/// <summary>
		/// ������ ��������� ������������ ����������.
		/// </summary>
		class SetDeviceConfigurationException : public std::exception
		{
		public:
			SetDeviceConfigurationException(const char* message)
				: exception(message) {}

			SetDeviceConfigurationException()
				: exception() {}
		};
	}
}