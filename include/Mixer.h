#pragma once
#include <memory>
#include <stdexcept>
#include "ILogger.h"
#include "SliderMapper.h"
#include "ServerMessage.h"
#include "IServerObserver.h"

namespace AudioMix
{
	class Mixer: public IServerObserver
	{
	private:
		std::shared_ptr<ILogger> _logger;
		std::unique_ptr<SliderMapper> _sliderMapper;
	public:
		Mixer(std::shared_ptr<ILogger> logger, std::unique_ptr<SliderMapper>&& mapper);
		void MessageReceive(ServerMessage& serverMessage) const override;
	};
}