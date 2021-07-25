#pragma once

#include "IMeasurementReader.hpp"

namespace Eaton::Device
{
	// this class reads real data from device, not implemented at the moment !!!
	class MeasurementReader final : public IMeasurementReader
	{
	public:
		// reads current values from device
		virtual std::vector<DataModels::MeasuredValue> getMeasuredValues() override;
	};
}