#pragma once
#include <string>
#include <windows.h>
#include <audiopolicy.h>
#include <atlbase.h>

namespace AudioMix
{
	/// <summary>
	/// Аудио сессия.
	/// </summary>
	class AudioSession
	{
	private:
		std::wstring _name;
		DWORD _id;
		CComPtr<ISimpleAudioVolume> _volume;
	public:
		/// <summary>
		/// Конструктор.
		/// </summary>
		/// <param name="name">Имя.</param>
		/// <param name="id">Id.</param>
		/// <param name="volume">Мастер управления звука.</param>
		AudioSession(std::wstring name, DWORD id, CComPtr<ISimpleAudioVolume> volume);

		/// <summary>
		/// Получение имени.
		/// </summary>
		/// <returns>Ссылка на строку.</returns>
		const std::wstring& GetName();

		/// <summary>
		/// Получение Id.
		/// </summary>
		/// <returns>Id.</returns>
		DWORD GetId();

		/// <summary>
		/// Получение сколярного уровня громкости.
		/// </summary>
		/// <returns>Сколярный уровень громкости.</returns>
		float GetVolume();

		/// <summary>
		/// Установки сколярного уровня громкости.
		/// </summary>
		/// <param name="volume">Сколярный уровень громкости.</param>
		void SetVolume(float volume);
	};
}