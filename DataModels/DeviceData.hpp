#pragma once

#include <vector>
#include <nlohmann/json.hpp>

#include "DataTypes.hpp"
#include "MeasuredValue.hpp"

namespace Eaton::DataModels
{
	// contains all values measured by device per measurement period
	struct DeviceData
	{
		// device identifier
		DeviceId deviceId;

		// measured values
		std::vector<MeasuredValue> values;
	};

	// save to json
	void to_json(nlohmann::json& j, const DeviceData& data);

	// load from json
	void from_json(const nlohmann::json& j, DeviceData& data);

	std::string serializeToJson(const DeviceData& data);

	DeviceData deserializeFromJson(const std::string& data);
}