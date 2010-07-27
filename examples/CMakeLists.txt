cmake_minimum_required(VERSION 2.6)
project(examples)

include($ENV{OpenCV_DIR}/OpenCVConfig.cmake)
include_directories(${OPENCV_INCLUDE_DIR})

add_executable(example1 example2-1.cpp)
add_executable(example2 example2-2.cpp)
add_executable(example3 example2-3.cpp)
add_executable(example4 example2-4.cpp)
add_executable(example5 example2-5.cpp)
add_executable(example6 example2-6.cpp)
add_executable(example6debug example2-6debug.cpp)
add_executable(alphablend alphablend.cpp)

target_link_libraries(example1 ${OpenCV_LIBS})
target_link_libraries(example2 ${OpenCV_LIBS})
target_link_libraries(example3 ${OpenCV_LIBS})
target_link_libraries(example4 ${OpenCV_LIBS})
target_link_libraries(example5 ${OpenCV_LIBS})
target_link_libraries(example6 ${OpenCV_LIBS})
target_link_libraries(example6debug ${OpenCV_LIBS})
target_link_libraries(alphablend ${OpenCV_LIBS})


