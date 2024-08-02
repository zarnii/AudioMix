#pragma once
#include <memory>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "IServer.h"
#include "ILogger.h"
#include "ServerConfig.h"
#include "Normalizer.h"

namespace AudioMix
{
	class MockServer : public IServer
	{
	private:
		std::shared_ptr<ILogger> _logger;
		std::shared_ptr<Normalizer> _normalizer;
		ServerConfig _config;
		bool _listening;
		std::vector<std::shared_ptr<IServerObserver>> _observers;
		
	public:
		/// <summary>
		/// Конструктор.
		/// </summary>
		/// <param name="logger">Логгер.</param>
		/// <param name="normalizer">Нормалайзер.</param>
		/// <param name="serverConfig">Конфиг сервера.</param>
		MockServer(std::shared_ptr<ILogger> logger, 
			std::shared_ptr<Normalizer> normalizer, 
			ServerConfig& serverConfig);

		/// <summary>
		/// Запуск прослушивания входящих сообщений.
		/// </summary>
		void StartListen() override;

		/// <summary>
		/// Остановка прослушивания входящих сообщений.
		/// </summary>
		void StopListen() override;

		/// <summary>
		/// Добавление наблюдателя.
		/// </summary>
		/// <param name="observer">Наблюдатель.</param>
		void virtual AddObserver(std::shared_ptr<IServerObserver> observer) override;
	};
}