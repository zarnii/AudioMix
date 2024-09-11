#pragma once
#include <vector>
#include "IServer.h"
#include "PortSerializer.h"
#include "Normalizer.h"

namespace AudioMix
{
	class ComPortServer: public IServer
	{
		std::shared_ptr<ILogger> _logger;
		std::vector<std::shared_ptr<IServerObserver>> _observers;
		PortSerializer _portSerializer;
		Normalizer _normalizer;
		bool _isListening;
		void NotifyObservers(ServerMessage& serverMessage);

	public:
		ComPortServer(std::string portName, std::shared_ptr<ILogger> logger, Normalizer&& normalizer);
		~ComPortServer();
		void StartListen() override;
		void StopListen() override;
		void AddObserver(std::shared_ptr<IServerObserver> observer) override;
		void DeleteObserver(std::shared_ptr<IServerObserver> observer) override;
	};
}