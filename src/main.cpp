#include <iostream>
#include "AudioMix.h"


int main()
{
	try 
	{
		auto portName = std::string("\\\.\\COM4");
		auto logger = std::make_shared<AudioMix::ConsoleLogger>();
		auto normalizer = AudioMix::Normalizer(0, 1024);
		auto server = AudioMix::ComPortServer(portName, logger, std::move(normalizer));
		auto audioSessionFactory = AudioMix::AudioSessionFactory(logger);
		auto audioSessions = audioSessionFactory.GetAudioSessions();
		auto mapperConfig = AudioMix::MapperConfig();
		mapperConfig.sliderCount = 5;
		auto sliderMapper = std::make_unique<AudioMix::SliderMapper>(logger, mapperConfig);

		for (size_t i = 0; i < audioSessions.size(); i++)
		{
			sliderMapper->BindSlider(i, audioSessions.at(i));
		}

		auto mixer = std::make_shared<AudioMix::Mixer>(logger, std::move(sliderMapper));
		server.AddObserver(mixer);
		server.StartListen();

	}
	catch (std::exception& ex)
	{
		std::cout << ex.what();
	}
}