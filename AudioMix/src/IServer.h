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
		/// Включение прослушивания входящих сообщений.
		/// </summary>
		void virtual StartListen() = 0;

		/// <summary>
		/// Остановки прослушивания входящих сообщений.
		/// </summary>
		void virtual StopListen() = 0;

		/// <summary>
		/// Добавление наблюдателя.
		/// </summary>
		/// <param name="observer">Наблюдатель.</param>
		void virtual AddObserver(std::shared_ptr<IServerObserver> observer) = 0;
	};
}