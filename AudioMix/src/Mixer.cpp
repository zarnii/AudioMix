#include "Mixer.h"

namespace AudioMix
{
	void Mixer::MessageReceive(ServerMessage& serverMessage)
	{
		_logger->LogInforamtion("Get server message.");
		_sliderMapper->SetVolume(serverMessage.sliderNumber, serverMessage.value);
	}

	Mixer::Mixer(std::shared_ptr<ILogger> logger, std::unique_ptr<SliderMapper>&& mapper)
	{
		_logger = logger;
		_sliderMapper = std::move(mapper);
	}
}