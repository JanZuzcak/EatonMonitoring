#include <DataModels/DataTypes.hpp>

#include "DummyMeasurementReader.hpp"

namespace Eaton::Device
{
	using namespace DataModels;

	DummyMeasurementReader::DummyMeasurementReader()
		: m_generator(m_randDev())
		, m_pwrDistr(0, 2000)
		, m_tempDistr(-50, 50)
		, m_voltDistr(0, 250)
	{
	}

	std::vector<MeasuredValue> DummyMeasurementReader::getMeasuredValues()
	{
		//create some dummy data
		std::vector<MeasuredValue> values
		{
			{ Unit::Power_W, Clock::now(), ValueStatus::Ok, static_cast<float>(m_pwrDistr(m_generator)) },
			{ Unit::InTemperature_degC, Clock::now(), ValueStatus::Ok, static_cast<float>(m_tempDistr(m_generator)) },
			{ Unit::Voltage_V, Clock::now(), ValueStatus::Ok, static_cast<float>(m_voltDistr(m_generator)) }
		};

		return values;
	}
}