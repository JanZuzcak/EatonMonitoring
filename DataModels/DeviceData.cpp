#include "DeviceData.hpp"

using json = nlohmann::json;

namespace Eaton::DataModels
{
	void to_json(json& j, const DeviceData& data)
	{
		j = json{
			{"deviceId", data.deviceId},
			{"values", data.values}};
	}

	void from_json(const json& j, DeviceData& data)
	{
		j.at("deviceId").get_to(data.deviceId);
		j.at("values").get_to(data.values);
	}
	
	std::string serializeToJson(const DeviceData& data)
	{
		json j;
		to_json(j, data);

		return j.dump();
	}

	DeviceData deserializeFromJson(const std::string& buffer)
	{
		json j = json::parse(buffer);
		DeviceData data;

		from_json(j, data);

		return data;
	}
}
