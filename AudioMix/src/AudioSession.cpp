#include "AudioSession.h"

namespace AudioMix
{
	AudioSession::AudioSession(std::wstring name, DWORD id, CComPtr<ISimpleAudioVolume> volume)
	{
		if (volume == nullptr)
		{
			throw std::invalid_argument("Volume is null.");
		}

		_name = name;
		_id = id;
		_volume = volume;
	}


	const std::wstring& AudioSession::GetName()
	{
		return _name;
	}


	DWORD AudioSession::GetId()
	{
		return _id;
	}

	float AudioSession::GetVolume()
	{
		float volume;
		auto hResult = _volume->GetMasterVolume(&volume);

		if (hResult == S_OK)
		{
			return volume;
		}
		else if (hResult == AUDCLNT_E_DEVICE_INVALIDATED)
		{
			throw Exceptions::AudioEndpointException("Audio endpoint was disable or was reset.");
		}

		throw Exceptions::AudioServiceNotRunning("Audio service not running.");
	}

	void AudioSession::SetVolume(float volume)
	{
		_volume->SetMasterVolume(volume, NULL);
	}
}