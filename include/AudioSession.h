#pragma once
#include <string>
#include <windows.h>
#include <audiopolicy.h>
#include <atlbase.h>
#include "Exceptions.h"

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
		std::wstring GetName() const;

		/// <summary>
		/// Получение Id.
		/// </summary>
		/// <returns>Id.</returns>
		DWORD GetId() const;

		/// <summary>
		/// Получение сколярного уровня громкости.
		/// </summary>
		/// <returns>Сколярный уровень громкости.</returns>
		float GetVolume() const;

		/// <summary>
		/// Установки сколярного уровня громкости.
		/// </summary>
		/// <param name="volume">Сколярный уровень громкости.</param>
		void SetVolume(float volume);
	};
}