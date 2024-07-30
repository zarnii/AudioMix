#pragma once
#include "ServerMessage.h"

namespace AudioMix
{
	class IServerObserver
	{
	public:
		void virtual MessageReceive(ServerMessage& serverMessage) = 0;
	};
}