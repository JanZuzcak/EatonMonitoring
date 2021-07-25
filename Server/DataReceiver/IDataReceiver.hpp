#pragma once

#include <functional>
#include <DataModels/DeviceData.hpp>

namespace Eaton::Server 
{
	using dataCallback = std::function<void(DataModels::DeviceData const& data)>;

	// this interface defines methods to get data received from devices
	class IDataReceiver
	{
	public:
		virtual ~IDataReceiver() = default;

		// register callback for received data
		virtual void regDataReceivedClbk(dataCallback clbk) = 0;

		// starts to receive data from devices, called at application start up
		virtual void startReceive() = 0;

		// stops receiving, called when the application is going down
		virtual void shutDown() = 0;
	};
}