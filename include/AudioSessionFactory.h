#pragma once
#include <memory>
#include <vector>
#include <mmdeviceapi.h>
#include <stdexcept>
#include "AudioSession.h"
#include "ILogger.h"
#include "ProcessHandler.h"

namespace AudioMix
{
	/// <summary>
	/// Фабрика аудио сессий.
	/// </summary>
	class AudioSessionFactory
	{
	private:
		/// <summary>
		/// Логгер.
		/// </summary>
		std::shared_ptr<ILogger> _logger;

		/// <summary>
		/// Проверка HRESULT.
		/// Exceptions:
		/// std::runtime_error - Если HRESULT сигнализирует о неудачном завершении функции.
		/// </summary>
		/// <param name="hResult">Состояние завершения функции.</param>
		/// <param name="errorMessage">Текст сообщения для отображения в ошибке.</param>
		void CheckHResultIsCorrect(HRESULT hResult, const std::string& errorMessage);

	public:
		AudioSessionFactory(std::shared_ptr<ILogger> logger);

		/// <summary>
		/// Получение всех аудиосессий.
		/// </summary>
		/// <returns>Коллекция аудиосессий.</returns>
		std::vector<std::shared_ptr<AudioSession>> GetAudioSessions();
	};
}