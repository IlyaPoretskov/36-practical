cmake_minimum_required(VERSION 3.5)

project(ColorfulCircleApp)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5Widgets REQUIRED)

add_executable(ColorfulCircleApp main.cpp)

target_link_libraries(ColorfulCircleApp Qt5::Widgets)
