#include "MockServer.h"

namespace AudioMix
{
	MockServer::MockServer(std::shared_ptr<ILogger> logger,
		std::shared_ptr<Normalizer> normalizer,
		ServerConfig& serverConfig)
	{
		if (logger == nullptr)
		{
			throw std::invalid_argument("Logger is null.");
		}

		if (normalizer == nullptr)
		{
			throw std::invalid_argument("Normalizer is null.");
		}

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
		if (observer == nullptr)
		{
			throw std::invalid_argument("Observer is null.");
		}

		_observers.push_back(observer);
	}

	void MockServer::DeleteObserver(std::shared_ptr<IServerObserver> observer)
	{
		auto new_end = std::remove(_observers.begin(), _observers.end(), observer);
		_observers.erase(new_end, _observers.end());
	}
}