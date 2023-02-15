cmake_minimum_required(VERSION 3.15)
project(webcam)

set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(webcam main.cpp)
target_link_libraries(webcam ${OpenCV_LIBS})