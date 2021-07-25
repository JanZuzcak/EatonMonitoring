#pragma once

#include <chrono>
#include <string>

namespace Eaton::DataModels
{
	using Clock = std::chrono::system_clock;
	using TimePoint = std::chrono::time_point<Clock>;
	using DeviceId = std::string;
}