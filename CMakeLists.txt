# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("EatonMonitoring")

#comment out following line for builds on linux
add_compile_definitions(_WIN32_WINNT=0x0601)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")

include_directories (.)
include_directories ("${PROJECT_SOURCE_DIR}/ThirdParty/json/single_include")
include_directories ("${PROJECT_SOURCE_DIR}/ThirdParty/asio/asio/include")

# Include sub-projects.
add_subdirectory ("DataModels")
add_subdirectory ("Device")
add_subdirectory ("Server")
