cmake_minimum_required(VERSION 3.27)
project(projeto_1)

set(CMAKE_CXX_STANDARD 17)

file(COPY src/Project1DataSetSmall/Project1DataSetSmall DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(project_2 src/main.cpp)