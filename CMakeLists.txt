cmake_minimum_required(VERSION 3.8)
project(OceanIO_Client)

include_directories(include)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp src/properties/Property.cpp include/properties/Property.h include/any.h src/InputParam.cpp include/InputParam.h)
add_executable(OceanIO_Client ${SOURCE_FILES})