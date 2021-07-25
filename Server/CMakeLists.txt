# CMakeList.txt : CMake project for Server, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Server   
				"main.cpp" 
				"DataReceiver/IDataReceiver.hpp" 
				"DataReceiver/DataReceiver.hpp" 
				"DataReceiver/DataReceiver.cpp" 
				"ServerManager.hpp" 
				"ServerManager.cpp"
				"DataProcessor/IDataProcessor.hpp"
				"DataProcessor/DataProcessor.hpp"
				"DataProcessor/DataProcessor.cpp")

target_link_libraries (Server DataModels)

# TODO: Add tests and install targets if needed.
