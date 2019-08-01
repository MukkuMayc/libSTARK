cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
project(onetest)

set(LIBS algebralib)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${LIBS})