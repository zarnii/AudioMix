#pragma once
#include <memory>
#include <iostream>
#include <vector>
#include "IServer.h"
#include "ILogger.h"
#include "ServerConfig.h"
#include "Normalizer.h"

namespace AudioMix
{
	class MockServer : public IServer
	{
	private:
		std::shared_ptr<ILogger> _logger;
		std::shared_ptr<Normalizer> _normalizer;
		ServerConfig _config;
		bool _listening;
		std::vector<std::shared_ptr<IServerObserver>> _observers;
		
	public:
		/// <summary>
		/// �����������.
		/// </summary>
		/// <param name="logger">������.</param>
		/// <param name="normalizer">�����������.</param>
		/// <param name="serverConfig">������ �������.</param>
		MockServer(std::shared_ptr<ILogger> logger, 
			std::shared_ptr<Normalizer> normalizer, 
			ServerConfig& serverConfig);

		/// <summary>
		/// ������ ������������� �������� ���������.
		/// </summary>
		void StartListen() override;

		/// <summary>
		/// ��������� ������������� �������� ���������.
		/// </summary>
		void StopListen() override;

		/// <summary>
		/// ���������� �����������.
		/// </summary>
		/// <param name="observer">�����������.</param>
		void virtual AddObserver(std::shared_ptr<IServerObserver> observer) override;
	};
}