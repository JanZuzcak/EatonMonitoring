# CMakeList.txt : CMake project for Server, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's library.
add_library (DataModels "MeasuredValue.cpp" "MeasuredValue.hpp" "DeviceData.cpp" "DeviceData.hpp" "Units.hpp")

# TODO: Add tests and install targets if needed.
