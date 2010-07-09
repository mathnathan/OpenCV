CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
project(examples)

INCLUDE($ENV{OpenCV_DIR}/OpenCVConfig.cmake)
INCLUDE_DIRECTORIES (${OPENCV_INCLUDE_DIR})

ADD_LIBRARY(natelib natelib.cpp)

ADD_EXECUTABLE(example1 example2-1.cpp)
ADD_EXECUTABLE(example2 example2-2.cpp)
ADD_EXECUTABLE(example3 example2-3.cpp)

TARGET_LINK_LIBRARIES (example1 ${OpenCV_LIBS} natelib)
TARGET_LINK_LIBRARIES (example2 ${OpenCV_LIBS} natelib)
TARGET_LINK_LIBRARIES (example3 ${OpenCV_LIBS} natelib)


