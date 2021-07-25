#include "MeasuredValue.hpp"

using json = nlohmann::json;

namespace Eaton::DataModels
{
	void to_json(json& j, const MeasuredValue& measurement)
	{
		j = json{ 
			{"unit", measurement.unit}, 
			{"time", Clock::to_time_t(measurement.time)}, 
			{"status", measurement.status},
			{"value", measurement.value} };
	}

	void from_json(const json& j, MeasuredValue& measurement)
	{
		measurement.unit = j.at("unit");
		measurement.status = j.at("status");
		measurement.time = Clock::from_time_t(j.at("time"));
		measurement.value = j.at("value");
	}
}
