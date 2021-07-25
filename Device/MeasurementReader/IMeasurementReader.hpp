#pragma once

#include <DataModels/MeasuredValue.hpp>

namespace Eaton::Device
{
	// interface defines methods for reading currently measured values of device 
	class IMeasurementReader
	{
	public:
		virtual ~IMeasurementReader() = default;

		// reads current values from device
		virtual std::vector<DataModels::MeasuredValue> getMeasuredValues() = 0;
	};
}