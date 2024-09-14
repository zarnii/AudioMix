#include "Mixer.h"

namespace AudioMix
{
	void Mixer::MessageReceive(ServerMessage& serverMessage) const
	{
		_logger->LogInforamtion("Get server message.", std::string(NAMEOF(Mixer::MessageReceive)));
		_sliderMapper->SetVolume(serverMessage.sliderNumber, serverMessage.value);
	}

	Mixer::Mixer(std::shared_ptr<ILogger> logger, std::unique_ptr<SliderMapper>&& mapper)
	{
		if (logger == nullptr)
		{
			throw std::invalid_argument("Logger is null.");
		}

		if (mapper == nullptr)
		{
			throw std::invalid_argument("Mapper is null.");
		}

		_logger = logger;
		_sliderMapper = std::move(mapper);
	}
}