#pragma once

#include <asio.hpp>
#include <atomic>
#include <cstdint>
#include <mutex>
#include <string>
#include <thread>

#include "IDataReceiver.hpp"

namespace Eaton::Server
{
	// the class receives data from all devices and notifies all subscribers via callbacks
	class DataReceiver : public IDataReceiver
	{
	public:
		DataReceiver(std::uint16_t portNum);

		// register callback for received data
		virtual void regDataReceivedClbk(dataCallback clbk) override;

		// starts to receive data from devices, called at application start up
		virtual void startReceive() override;

		// stops receiving, called when the application is going down
		virtual void shutDown() override;

	private:
		void handleReceive();

	private:
		const std::size_t cBufferSize = 4096;

		std::vector<dataCallback> m_callbacks;
		asio::io_service m_ios;
		asio::ip::udp::socket m_sock;
		asio::ip::udp::endpoint m_recvEndpoint;
		asio::ip::udp::endpoint m_devEndPoint;
		std::string m_recvBuffer;
		std::atomic<bool> m_shutDown;
		std::thread m_workThread;
		std::once_flag m_recvStarted;
		std::once_flag m_recvFinished;
	};
}