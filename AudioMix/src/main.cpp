#include <iostream>
#include "AudioMix.h"


int main()
{
	/*
	AudioMix::ServerConfig serverConfig;
	auto logger = std::make_shared<AudioMix::ConsoleLogger>();
	auto normalizer = std::make_shared<AudioMix::Normalizer>(0, 100);
	auto server = std::make_unique<AudioMix::MockServer>(logger, normalizer, serverConfig);
	auto sliderMapper = std::make_unique<AudioMix::SliderMapper>(logger);
	auto mixer = std::make_shared<AudioMix::Mixer>(logger, std::move(sliderMapper));
	server->AddObserver(mixer);
	server->StartListen();
	*/
	auto logger = std::make_shared<AudioMix::ConsoleLogger>();
	logger->LogInforamtion("Test info", std::string(NAMEOF(AudioMix::MockServer)));
	logger->LogError("Test error", std::string(NAMEOF(AudioMix::SliderMapper)));
}