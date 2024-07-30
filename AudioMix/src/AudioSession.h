#pragma once
#include <string>
#include <windows.h>
#include <audiopolicy.h>
#include <atlbase.h>

namespace AudioMix
{
	/// <summary>
	/// ����� ������.
	/// </summary>
	class AudioSession
	{
	private:
		std::wstring _name;
		DWORD _id;
		CComPtr<ISimpleAudioVolume> _volume;
	public:
		/// <summary>
		/// �����������.
		/// </summary>
		/// <param name="name">���.</param>
		/// <param name="id">Id.</param>
		/// <param name="volume">������ ���������� �����.</param>
		AudioSession(std::wstring name, DWORD id, CComPtr<ISimpleAudioVolume> volume);

		/// <summary>
		/// ��������� �����.
		/// </summary>
		/// <returns>������ �� ������.</returns>
		const std::wstring& GetName();

		/// <summary>
		/// ��������� Id.
		/// </summary>
		/// <returns>Id.</returns>
		DWORD GetId();

		/// <summary>
		/// ��������� ���������� ������ ���������.
		/// </summary>
		/// <returns>��������� ������� ���������.</returns>
		float GetVolume();

		/// <summary>
		/// ��������� ���������� ������ ���������.
		/// </summary>
		/// <param name="volume">��������� ������� ���������.</param>
		void SetVolume(float volume);
	};
}