#include "ComPortServer.h"

namespace AudioMix
{
	// Public methods start.
	ComPortServer::ComPortServer(std::string portName, std::shared_ptr<ILogger> logger, Normalizer&& normalizer)
		: _portSerializer(portName, logger), 
		_normalizer(normalizer), 
		_isListening(false)
	{}

	ComPortServer::~ComPortServer()
	{}

	void ComPortServer::AddObserver(std::shared_ptr<IServerObserver> observer)
	{
		_observers.push_back(observer);
	}

	void ComPortServer::DeleteObserver(std::shared_ptr<IServerObserver> observer)
	{
		auto newEnd = std::remove(_observers.begin(), _observers.end(), observer);
		_observers.erase(newEnd, _observers.end());
	}

	void ComPortServer::StartListen()
	{
		_isListening = true;

		while (_isListening)
		{
			auto recievedMessage = _portSerializer.ReadData();
			auto serverMessage = ServerMessage();
			size_t delimiterIndex = recievedMessage.find('-');
			serverMessage.sliderNumber = static_cast<uint8_t>(std::stoi(recievedMessage.substr(0, delimiterIndex)));
			auto sliderValue = static_cast<size_t>(std::stoi(recievedMessage.substr(delimiterIndex + 1, recievedMessage.length())));
			serverMessage.value = _normalizer.Normalize(sliderValue);

			NotifyObservers(serverMessage);
		}
	}

	void ComPortServer::StopListen()
	{
		_isListening = false;
	}
	// Public methods end.


	// Private methods start.
	void ComPortServer::NotifyObservers(ServerMessage& serverMessage)
	{
		for (auto& observer : _observers)
		{
			observer->MessageReceive(serverMessage);
		}
	}
	// Private methods end.
}