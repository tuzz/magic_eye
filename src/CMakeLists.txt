cmake_minimum_required(VERSION 2.6)
project(magic_eye)

find_package(OpenCV REQUIRED)

add_executable(magic_eye main.cpp offset.cpp)
target_link_libraries(magic_eye ${OpenCV_LIBS})
