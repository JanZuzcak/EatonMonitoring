#pragma once

#include <nlohmann/json.hpp>

#include "DataTypes.hpp"
#include "Units.hpp"

namespace Eaton::DataModels
{
	// contains info about measurement 
	struct MeasuredValue
	{
		// physical unit of measured value
		Unit unit;

		// time of measurement
		TimePoint time;

		// values status
		ValueStatus status;

		// measuered value
		float value;
	};

	// save to json
	void to_json(nlohmann::json& j, const MeasuredValue& measurement);

	// load from json
	void from_json(const nlohmann::json& j, MeasuredValue& measurement);
}
