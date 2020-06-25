#pragma once
#include <Platform/Platform.h>
#include <Network/Socket.h>
#include <queue>
#include <map>
#include <Utilities/Thread.h>
#include "NetworkTypes.h"

namespace Stardust::Network {
	typedef int (*PacketHandler)(PacketIn*);

	class NetworkDriver {
	public:
		
		NetworkDriver();
		bool Init();
		bool Connect(unsigned short port, const char* ip, bool threaded);
		void Cleanup();

		void AddPacket(PacketOut* p);
		void ClearPacketQueue();
		void SendPackets(bool extendedID = true);

		void ReceivePacket(bool extendedID = true);
		void HandlePackets();

		void AddPacketHandler(int id, PacketHandler h);
		void ClearPacketHandlers();

		std::queue<PacketOut*> packetQueue;
		std::queue<PacketIn*> unhandledPackets;
		std::map<int, PacketHandler> packetHandlers;

		Socket m_Socket;
	private:

#if CURRENT_PLATFORM == PLATFORM_PSP
		static int ReceiveThread(SceSize args, void* argp);
#endif
		Utilities::Thread* thr;
	};

	extern NetworkDriver g_NetworkDriver;
}