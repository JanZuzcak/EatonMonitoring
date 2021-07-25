#pragma once
#include <cstdint>

namespace Eaton::DataModels
{
	// enum defines list of supported physical units of values measured by device
	enum class Unit : std::uint16_t
	{
		InTemperature_degC,		// inside temperature [C]
		OutTemperature_degC,	// outside temperature [C]
		Power_W,				// electric power [W]
		Voltage_V,				// voltage [V]
		Current_A,				// current [A]

		//any other physical units to be defined...
	};

	// enum defines list of error states of values measured by device
	enum class ValueStatus : std::uint8_t
	{
		Ok,
		SensorError_1,
		SensorError_2,

		//list of possible errors...
	};
}