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
		MapperConfig _config;
		std::unordered_map<size_t, std::shared_ptr<AudioSession>> _map;
		std::shared_ptr<ILogger> _logger;
	public:
		/// <summary>
		/// Конструктор.
		/// </summary>
		/// <param name="logger">Логгер.</param>
		/// <param name="config">Конфиг.</param>
		SliderMapper(std::shared_ptr<ILogger> logger, MapperConfig config);

		~SliderMapper();
		
		/// <summary>
		/// Установка звука.
		/// </summary>
		/// <param name="sliderNumber">Номер ползунка.</param>
		/// <param name="volume">Уровень звука от 0 до 1.</param>
		void SetVolume(size_t sliderNumber, float volume);

		/// <summary>
		/// Получение звука.
		/// </summary>
		/// <param name="sliderNumber">Номер позвунка.</param>
		/// <returns>Уровень звука от 0 до 1.</returns>
		float GetVolume(size_t sliderNumber);

		/// <summary>
		/// Биндинг аудиосессии к номеру ползунка.
		/// </summary>
		/// <param name="sliderNumber">Номер ползунка начиная с 0.</param>
		/// <param name="audioSession">Аудиосессия.</param>
		void BindSlider(size_t sliderNumber, std::shared_ptr<AudioSession> audioSession);
	};
}