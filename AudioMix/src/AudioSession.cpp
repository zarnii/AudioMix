#include "AudioSession.h"

namespace AudioMix
{
	AudioSession::AudioSession(std::wstring name, DWORD id, CComPtr<ISimpleAudioVolume> volume)
	{
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

		// to-do: Кидать ошибку.
		return -1;
	}

	void AudioSession::SetVolume(float volume)
	{
		_volume->SetMasterVolume(volume, NULL);
	}
}