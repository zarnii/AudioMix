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
		CComPtr<IMMDeviceEnumerator> deviceEnumerator;
		CComPtr<IMMDevice> defaultDevice;
		CComPtr<IAudioSessionManager2> audioSessionManager;
		CComPtr<IAudioSessionEnumerator> audioSessionEnumerator;
		CComPtr<IAudioSessionControl> audioSessionControl;
		CComPtr<IAudioSessionControl2> audioSessionControl2;

		auto hResult = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
		CheckHResultIsCorrect(hResult, "COM initialization error.");
		_logger->LogInforamtion("COM initialization success.",
			std::string(NAMEOF(AudioSessionFactory::GetAudioSessions)));

		hResult = deviceEnumerator.CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER);
		CheckHResultIsCorrect(hResult, "Create COM instanse error.");
		_logger->LogInforamtion("Create device enumerator success.",
			std::string(NAMEOF(AudioSessionFactory::GetAudioSessions)));

		hResult = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eMultimedia, &defaultDevice.p);
		CheckHResultIsCorrect(hResult, "Get default audio endpoint error.");
		_logger->LogInforamtion("Get default audio endpoint success",
			std::string(NAMEOF(AudioSessionFactory::GetAudioSessions)));

		hResult = defaultDevice->Activate(__uuidof(IAudioSessionManager2), CLSCTX_INPROC_SERVER, NULL, (void**)&audioSessionManager.p);
		CheckHResultIsCorrect(hResult, "Activate audio session manager error.");
		_logger->LogInforamtion("Activate audio session manager success.",
			std::string(NAMEOF(AudioSessionFactory::GetAudioSessions)));

		hResult = audioSessionManager->GetSessionEnumerator(&audioSessionEnumerator.p);
		CheckHResultIsCorrect(hResult, "Get audio session enumerator error.");
		_logger->LogInforamtion("Get audio session enumerator success.",
			std::string(NAMEOF(AudioSessionFactory::GetAudioSessions)));

		size_t sessionCount = 0;
		hResult = audioSessionEnumerator->GetCount((int*)&sessionCount);
		CheckHResultIsCorrect(hResult, "Get count audio session error.");
		_logger->LogInforamtion("Get count audio session success.",
			std::string(NAMEOF(AudioSessionFactory::GetAudioSessions)));

		auto audioSessions = 
			std::vector<std::shared_ptr<AudioSession>>();

		for (size_t i = 0; i < sessionCount; i++)
		{
			hResult = audioSessionEnumerator->GetSession(i, &audioSessionControl.p);
			CheckHResultIsCorrect(hResult, "Get audio session error.");
			_logger->LogInforamtion("Get audio session success.",
				std::string(NAMEOF(AudioSessionFactory::GetAudioSessions)));

			audioSessionControl->QueryInterface<IAudioSessionControl2>(&audioSessionControl2.p);
			DWORD pid;
			hResult = audioSessionControl2->GetProcessId(&pid);
			CheckHResultIsCorrect(hResult, "Get process id error.");
			_logger->LogInforamtion("Get process id success",
				std::string(NAMEOF(AudioSessionFactory::GetAudioSessions)));

			auto processName = ProcessHandler::GetProcessNameByPid(pid);
			CComPtr<ISimpleAudioVolume> volume;
			audioSessionControl->QueryInterface<ISimpleAudioVolume>(&volume.p);

			audioSessions.push_back(std::make_shared<AudioSession>(processName, pid, volume));

			_logger->LogInforamtion("Create AudioSession success.",
				std::string(NAMEOF(AudioSessionFactory::GetAudioSessions)));
		}

		CoUninitialize();

		return audioSessions;
	}
}