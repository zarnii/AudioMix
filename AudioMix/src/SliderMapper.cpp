#include "SliderMapper.h"

namespace AudioMix
{
	SliderMapper::SliderMapper(std::shared_ptr<ILogger> logger)
	{
		_logger = logger;
		InitMap();
		_logger->LogInforamtion("SliderMapper was created successfully.");
	}

	void SliderMapper::SetVolume(uint8_t sliderNumber, float volume)
	{
		_map[sliderNumber]->SetVolume(volume);
		_logger->LogInforamtion(std::format("Set new volume, {} slider: {} volume", sliderNumber, volume));
	}

	float SliderMapper::GetVolume(uint8_t sliderNumber)
	{
		_logger->LogInforamtion(std::format("Get volume from {} slider", sliderNumber));
		return _map[sliderNumber]->GetVolume();
	}

	void SliderMapper::CheckHResult(HRESULT hResult, const std::string& errorMessage)
	{
		if (FAILED(hResult))
		{
			_logger->LogError(errorMessage);
			throw std::runtime_error(errorMessage);
		}
	}

	void SliderMapper::InitMap()
	{
		CComPtr<IMMDeviceEnumerator> deviceEnumerator;
		CComPtr<IMMDevice> defaultDevice;
		CComPtr<IAudioSessionManager2> audioSessionManager;
		CComPtr<IAudioSessionEnumerator> audioSessionEnumerator;
		CComPtr<IAudioSessionControl> audioSessionControl;
		CComPtr<IAudioSessionControl2> audioSessionControl2;
		
		auto hResult = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
		CheckHResult(hResult, "COM initialization error.");
		_logger->LogInforamtion("COM initialization success.");

		hResult = deviceEnumerator.CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER);
		CheckHResult(hResult, "Create COM instanse error.");
		_logger->LogInforamtion("Create device enumerator success.");

		hResult = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eMultimedia, &defaultDevice.p);
		CheckHResult(hResult, "Get default audio endpoint error.");
		_logger->LogInforamtion("Get default audio endpoint success");

		hResult = defaultDevice->Activate(__uuidof(IAudioSessionManager2), CLSCTX_INPROC_SERVER, NULL, (void**)&audioSessionManager.p);
		CheckHResult(hResult, "Activate audio session manager error.");
		_logger->LogInforamtion("Activate audio session manager success.");

		hResult = audioSessionManager->GetSessionEnumerator(&audioSessionEnumerator.p);
		CheckHResult(hResult, "Get audio session enumerator error.");
		_logger->LogInforamtion("Get audio session enumerator success.");

		uint32_t sessionCount = 0;
		hResult = audioSessionEnumerator->GetCount((int*)&sessionCount);
		CheckHResult(hResult, "Get count audio session error.");
		_logger->LogInforamtion("Get count audio session success.");

		for (int32_t i = 0; i < sessionCount; i++)
		{
			hResult = audioSessionEnumerator->GetSession(i, &audioSessionControl.p);
			CheckHResult(hResult, "Get audio session error.");
			_logger->LogInforamtion("Get audio session success.");

			audioSessionControl->QueryInterface<IAudioSessionControl2>(&audioSessionControl2.p);
			DWORD pid;
			hResult = audioSessionControl2->GetProcessId(&pid);
			CheckHResult(hResult, "Get process id error.");
			_logger->LogInforamtion("Get process id success");

			auto processName = ProcessHandler::GetProcessNameByPid(pid);
			CComPtr<ISimpleAudioVolume> volume;
			audioSessionControl->QueryInterface<ISimpleAudioVolume>(&volume.p);

			_map[i] = std::make_unique<AudioSession>(processName, pid, volume);
			_logger->LogInforamtion("Create AudioSession success.");
		}

		CoUninitialize();
	}
}