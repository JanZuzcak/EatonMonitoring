#include <exception>

#include "MeasurementReader.hpp"

namespace Eaton::Device
{
	using namespace DataModels;

	std::vector<MeasuredValue> MeasurementReader::getMeasuredValues()
	{
		throw std::exception("not implemented");
	}
}