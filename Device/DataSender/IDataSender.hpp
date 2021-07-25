#pragma once

#include <vector>

#include <DataModels/MeasuredValue.hpp>

namespace Eaton::Device
{
	// interface defines methods for sending measured values to server 
	class IDataSender
	{
	public:
		virtual ~IDataSender() = default;

		// sends data to server
		virtual bool sendData(const std::vector<DataModels::MeasuredValue>& data) = 0;
	};
}