cmake_minimum_required(VERSION 3.5)

project(DVS-Calibration)
find_package(OpenCV REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include/)

add_executable(gen src/gen_pattern.cpp src/PatternMaker.cpp)
target_link_libraries(gen ${OpenCV_LIBS})
