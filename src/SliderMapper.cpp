#include "SliderMapper.h"

namespace AudioMix
{
	SliderMapper::SliderMapper(std::shared_ptr<ILogger> logger, MapperConfig config)
		: _config(config)
	{
		if (logger == nullptr)
		{
			throw std::invalid_argument("Logger is null.");
		}

		_config = config;
		_logger = logger;

		_logger->LogInforamtion("SliderMapper was create.", NAMEOF(AudioMix::SliderMapper));
	}

	SliderMapper::~SliderMapper()
	{
		_logger->LogInforamtion("SliderMapper was deleted", NAMEOF(AudioMix::SliderMapper));
	}

	void SliderMapper::SetVolume(size_t sliderNumber, float volume) const
	{
		if (!_map.contains(sliderNumber))
		{
			return;
		}

		_map.at(sliderNumber)->SetVolume(volume);
		_logger->LogInforamtion(
			std::format("Set new volume, {} slider: {} volume", sliderNumber, volume),
			std::string(NAMEOF(SliderMapper::SetVolume)));
	}

	float SliderMapper::GetVolume(size_t sliderNumber) const
	{
		_logger->LogInforamtion(
			std::format("Get volume from {} slider", sliderNumber),
			std::string(NAMEOF(SliderMapper::GetVolume)));

		return _map.at(sliderNumber)->GetVolume();
	}

	void SliderMapper::BindSlider(size_t sliderNumber, std::shared_ptr<AudioSession> audioSession)
	{
		if (sliderNumber + 1 > _config.sliderCount)
		{
			throw std::invalid_argument("Slider number out of range.");
		}

		_map[sliderNumber] = audioSession;
	}
}