cmake_minimum_required(VERSION 3.15)
project(histogramEqualization)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(histogramEqualization main.cpp)
target_link_libraries(histogramEqualization ${OpenCV_LIBS})