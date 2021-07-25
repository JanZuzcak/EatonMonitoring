# CMakeList.txt : CMake project for Server, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Device 
				"main.cpp" 
				"MeasurementReader/IMeasurementReader.hpp"
				"MeasurementReader/DummyMeasurementReader.hpp" 
				"MeasurementReader/DummyMeasurementReader.cpp" 
				"MeasurementReader/MeasurementReader.hpp" 
				"MeasurementReader/MeasurementReader.cpp"
				"DataSender/IDataSender.hpp"
				"DataSender/DataSender.hpp"
				"DataSender/DataSender.cpp" 
				"DeviceManager.hpp" 
				"DeviceManager.cpp" 
				"Utils.hpp"
				)

target_link_libraries (Device DataModels)

# TODO: Add tests and install targets if needed.
