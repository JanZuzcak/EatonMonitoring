#pragma once
#include <atomic>
#include <memory>
#include <DataModels/DataTypes.hpp>

#include "DataSender/IDataSender.hpp"
#include "MeasurementReader/IMeasurementReader.hpp"

namespace Eaton::Device
{
	class DeviceManager
	{
	public:
		DeviceManager(std::shared_ptr<IDataSender> dataSender, std::shared_ptr<IMeasurementReader> measurementReader);

		void run();

		void shutDown();

	private:
		std::shared_ptr<IDataSender> m_dataSender;
		std::shared_ptr<IMeasurementReader> m_measurementReader;
		DataModels::TimePoint m_lastMeasTime;

		std::atomic<bool> m_shutDown;
	};
}
