#pragma once
#include <random>

#include "IMeasurementReader.hpp"

namespace Eaton::Device
{
	// this class generates some random data to simulate a real device
	class DummyMeasurementReader final : public IMeasurementReader
	{
	public:
		DummyMeasurementReader();

		// reads current values from device
		virtual std::vector<DataModels::MeasuredValue> getMeasuredValues() override;

	private:
		std::random_device m_randDev;
		std::mt19937 m_generator;
		std::uniform_int_distribution<> m_pwrDistr;
		std::uniform_int_distribution<> m_tempDistr;
		std::uniform_int_distribution<> m_voltDistr;
	};
}