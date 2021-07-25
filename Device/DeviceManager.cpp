#include <chrono>
#include <iostream>
#include <thread>

#include "Common/Constants.hpp"
#include "DeviceManager.hpp"

using namespace std;
using namespace std::chrono_literals;
using namespace Eaton::Common;
using namespace Eaton::DataModels;

namespace Eaton::Device
{
	DeviceManager::DeviceManager(shared_ptr<IDataSender> dataSender, shared_ptr<IMeasurementReader> measurementReader)
		: m_dataSender(dataSender)
		, m_measurementReader(measurementReader)
		, m_shutDown(false)
	{
	}

	void DeviceManager::run()
	{
		while(!m_shutDown)
		{
			//send measured data to server periodically
			if (auto now = Clock::now(); now - m_lastMeasTime > cSendDevDataPeriod)
			{
				m_lastMeasTime = now;

				auto data = m_measurementReader->getMeasuredValues();
				cout << "sending data to server" << endl;
				m_dataSender->sendData(data);
			}

			this_thread::sleep_for(1ms);
		}
	}

	void DeviceManager::shutDown()
	{
		m_shutDown = true;
	}
}