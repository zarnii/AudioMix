#include "MockServer.h"

namespace AudioMix
{
	MockServer::MockServer(std::shared_ptr<ILogger> logger,
		std::shared_ptr<Normalizer> normalizer,
		ServerConfig& serverConfig)
	{
		_logger = logger;
		_normalizer = normalizer;
		_config = serverConfig;
		_listening = true;
		_observers = std::vector<std::shared_ptr<IServerObserver>>();

		// _logger->LogInforamtion("The server was created successfully.");
	}

	void MockServer::StartListen()
	{
		while (_listening)
		{
			std::string message; 
			std::cin >> message;

			size_t delimiterPos = message.find("-");
			auto serverMessage = ServerMessage();
			serverMessage.sliderNumber = static_cast<int8_t>(std::stoi(message.substr(0, delimiterPos)));
			auto sliderValue = static_cast<size_t>(std::stoi(message.substr(delimiterPos + 1, message.length())));
			serverMessage.value = _normalizer->Normalize(sliderValue);

			for (auto& observer : _observers)
			{
				observer->MessageReceive(serverMessage);
			}
		}
	}

	void MockServer::StopListen()
	{
		_listening = false;
	}

	void MockServer::AddObserver(std::shared_ptr<IServerObserver> observer)
	{
		_observers.push_back(observer);
	}
}