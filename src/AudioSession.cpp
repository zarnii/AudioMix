#include "AudioSession.h"

namespace AudioMix
{
	AudioSession::AudioSession(std::wstring name, DWORD id, CComPtr<ISimpleAudioVolume> volume)
		: _name(name), _id (id)
	{
		if (volume == nullptr)
		{
			throw std::invalid_argument("Volume is null.");
		}

		_volume = volume;
	}


	std::wstring AudioSession::GetName() const
	{
		return _name;
	}


	DWORD AudioSession::GetId() const
	{
		return _id;
	}

	float AudioSession::GetVolume() const
	{
		float volume;
		auto hResult = _volume->GetMasterVolume(&volume);

		if (hResult == AUDCLNT_E_DEVICE_INVALIDATED)
		{
			throw Exceptions::AudioEndpointException("Audio endpoint was disable or was reset.");
		}

		if (hResult == AUDCLNT_E_SERVICE_NOT_RUNNING)
		{
			throw Exceptions::AudioServiceNotRunning("Audio service not running.");
		}

		return volume;
	}

	void AudioSession::SetVolume(float volume)
	{
		_volume->SetMasterVolume(volume, NULL);
	}
}