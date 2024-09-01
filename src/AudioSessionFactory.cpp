#include "AudioSessionFactory.h"

namespace AudioMix
{
	AudioSessionFactory::AudioSessionFactory(std::shared_ptr<ILogger> logger)
	{
		if (logger == nullptr)
		{
			throw std::invalid_argument("Logger is null.");
		}

		_logger = logger;
		_logger->LogInforamtion("The audio factory was created successfully.", 
			NAMEOF(AudioMix::AudioSessionFactory));
	}

	void AudioSessionFactory::CheckHResultIsCorrect(HRESULT hResult, const std::string& errorMessage)
	{
		if (FAILED(hResult))
		{
			_logger->LogError(errorMessage,
				std::string(NAMEOF(SliderMapper::CheckHResult)));
			throw std::runtime_error(errorMessage);
		}
	}

	std::vector<std::shared_ptr<AudioSession>> 
		AudioSessionFactory::GetAudioSessions()
	{
		_logger->LogInforamtion("Started getting audio sessions.",
			NAMEOF(AudioSessionFactory::GetAudioSessions));

		CComPtr<IMMDeviceEnumerator> deviceEnumerator;
		CComPtr<IMMDevice> defaultDevice;
		CComPtr<IAudioSessionManager2> audioSessionManager;
		CComPtr<IAudioSessionEnumerator> audioSessionEnumerator;
		CComPtr<IAudioSessionControl> audioSessionControl;
		CComPtr<IAudioSessionControl2> audioSessionControl2;
		size_t sessionCount = 0;
		size_t createdAudioSessionCount = 0;
		auto hResult = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

		try 
		{
			CheckHResultIsCorrect(hResult, "COM initialization error.");

			hResult = deviceEnumerator.CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER);
			CheckHResultIsCorrect(hResult, "Create COM instanse error.");

			hResult = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eMultimedia, &defaultDevice.p);
			CheckHResultIsCorrect(hResult, "Get default audio endpoint error.");

			hResult = defaultDevice->Activate(__uuidof(IAudioSessionManager2), CLSCTX_INPROC_SERVER, NULL, (void**)&audioSessionManager.p);
			CheckHResultIsCorrect(hResult, "Activate audio session manager error.");

			hResult = audioSessionManager->GetSessionEnumerator(&audioSessionEnumerator.p);
			CheckHResultIsCorrect(hResult, "Get audio session enumerator error.");


			hResult = audioSessionEnumerator->GetCount((int*)&sessionCount);
			CheckHResultIsCorrect(hResult, "Get count audio session error.");
			_logger->LogInforamtion(std::format("Detected {} audio sessions", sessionCount),
				std::string(NAMEOF(AudioSessionFactory::GetAudioSessions)));
		}
		catch (std::exception& ex)
		{
			_logger->LogError(ex.what(), NAMEOF(AudioSessionFactory::GetAudioSessions));
			CoUninitialize();
			throw ex;
		}
		

		auto audioSessions =
			std::vector<std::shared_ptr<AudioSession>>();

		for (size_t i = 0; i < sessionCount; i++)
		{
			try 
			{
				hResult = audioSessionEnumerator->GetSession(i, &audioSessionControl.p);
				CheckHResultIsCorrect(hResult, "Get audio session error.");

				audioSessionControl->QueryInterface<IAudioSessionControl2>(&audioSessionControl2.p);
				DWORD pid;
				hResult = audioSessionControl2->GetProcessId(&pid);
				CheckHResultIsCorrect(hResult, "Get process id error.");

				auto processName = ProcessHandler::GetProcessNameByPid(pid);
				CComPtr<ISimpleAudioVolume> volume;
				audioSessionControl->QueryInterface<ISimpleAudioVolume>(&volume.p);
				audioSessions.push_back(std::make_shared<AudioSession>(processName, pid, volume));

				createdAudioSessionCount++;
				_logger->LogInforamtion(
					std::format("Creating audio session {} of {} (pid: {})",
						createdAudioSessionCount, sessionCount, pid), NAMEOF(AudioSessionFactory::GetAudioSessions));
			}
			catch (std::exception& ex)
			{
				_logger->LogError(ex.what(), NAMEOF(AudioSessionFactory::GetAudioSessions));
			}
		}

		CoUninitialize();

		_logger->LogInforamtion("End getting audio sessions.",
			NAMEOF(AudioSessionFactory::GetAudioSessions));

		return audioSessions;
	}
}