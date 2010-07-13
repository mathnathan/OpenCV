cmake_minimum_required(VERSION 2.6)
project(examples)

include($ENV{OpenCV_DIR}/OpenCVConfig.cmake)
include_directories(${OPENCV_INCLUDE_DIR})

add_executable(example1 example2-1.cpp)
add_executable(example2 example2-2.cpp)
add_executable(example3 example2-3.cpp)
add_executable(example4 example2-4.cpp)

target_link_libraries(example1 ${OpenCV_LIBS})
target_link_libraries(example2 ${OpenCV_LIBS})
target_link_libraries(example3 ${OpenCV_LIBS})
target_link_libraries(example4 ${OpenCV_LIBS})


