#pragma once
#include <unordered_map>
#include <cstdint>
#include <memory>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <audiopolicy.h>
#include <processthreadsapi.h>
#include <stdexcept>
#include <windows.h>
#include <format>
#include "MapperConfig.h"
#include "AudioSession.h"
#include "ILogger.h"
#include "ProcessHandler.h"

namespace AudioMix
{
	class SliderMapper
	{
	private:
		std::unordered_map<uint8_t, std::unique_ptr<AudioSession>> _map;
		std::shared_ptr<ILogger> _logger;
		void InitMap();
		void CheckHResult(HRESULT hResult, const std::string& errorMessage);
	public:
		SliderMapper(std::shared_ptr<ILogger> logger);
		void SetVolume(uint8_t sliderNumber, float volume);
		float GetVolume(uint8_t sliderNumber);
	};
}