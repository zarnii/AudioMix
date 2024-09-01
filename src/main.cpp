#include <iostream>
#include "AudioMix.h"


int main()
{
	try
	{
		AudioMix::ServerConfig serverConfig;
		auto logger = std::make_shared<AudioMix::ConsoleLogger>();
		auto normalizer = std::make_shared<AudioMix::Normalizer>(0, 100);
		auto server = std::make_unique<AudioMix::MockServer>(logger, normalizer, serverConfig);
		auto audioSessionFactory = std::make_shared<AudioMix::AudioSessionFactory>(logger);
		auto audioSessions = audioSessionFactory->GetAudioSessions();
		logger->LogInforamtion("Start create mapper config.", "main");

		auto mapperConfig = AudioMix::MapperConfig();
		mapperConfig.sliderCount = 5;
		logger->LogInforamtion("Mapper config was created.", "main");
		auto slider = std::make_unique<AudioMix::SliderMapper>(logger, mapperConfig);

		for (size_t i = 0; i < audioSessions.size(); i++)
		{
			slider->BindSlider(i, audioSessions.at(i));
		}

		auto mixer = std::make_shared<AudioMix::Mixer>(logger, std::move(slider));
		server->AddObserver(mixer);
		server->StartListen();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what();
	}
}