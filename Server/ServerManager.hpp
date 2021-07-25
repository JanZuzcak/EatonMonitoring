#pragma once
#include <asio.hpp>
#include <atomic>
#include <memory>
#include <DataModels/DataTypes.hpp>

#include "DataReceiver/IDataReceiver.hpp"
#include "DataProcessor/IDataProcessor.hpp"

namespace Eaton::Server
{
	class ServerManager
	{
	public:
		ServerManager(std::shared_ptr<IDataReceiver> dataReceiver, std::shared_ptr<IDataProcessor> dataProcessor);

		void run();

		void shutDown();

	private:
		std::shared_ptr<IDataReceiver> m_dataReceiver;
		std::shared_ptr<IDataProcessor> m_dataProcessor;

		DataModels::TimePoint m_lastReportTime;
		std::atomic<bool> m_shutDown;
	};
}