#pragma once
#include "ServerMessage.h"

namespace AudioMix
{
	class IServerObserver
	{
	public:
		/// <summary>
		/// Получение сообщения.
		/// </summary>
		/// <param name="serverMessage">Сообщение сервера.</param>
		void virtual MessageReceive(ServerMessage& serverMessage) = 0;
		
		/// <summary>
		/// Деструктор.
		/// </summary>
		virtual ~IServerObserver() = default;
	};
}