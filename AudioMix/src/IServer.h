#pragma once
#include <memory>
#include "ServerMessage.h"
#include "IServerObserver.h"

namespace AudioMix
{
	class IServer
	{
	public:
		/// <summary>
		/// ��������� ������������� �������� ���������.
		/// </summary>
		void virtual StartListen() = 0;

		/// <summary>
		/// ��������� ������������� �������� ���������.
		/// </summary>
		void virtual StopListen() = 0;

		/// <summary>
		/// ���������� �����������.
		/// </summary>
		/// <param name="observer">�����������.</param>
		void virtual AddObserver(std::shared_ptr<IServerObserver> observer) = 0;
	};
}