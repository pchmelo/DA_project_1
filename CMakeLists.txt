cmake_minimum_required(VERSION 3.27)
project(projeto_1)

set(CMAKE_CXX_STANDARD 17)

file(COPY src/Project1DataSetSmall/Project1DataSetSmall DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
include_directories(src/structs/aux)

add_executable(project_2 src/main.cpp
        src/structs/aux/Graph.h
        src/structs/aux/MutablePriorityQueue.h
        src/structs/data_type/Reservoir.h
        src/structs/data_type/Reservoir.cpp
        src/structs/data_type/City.h
        src/structs/data_type/City.cpp
        src/structs/data_type/Stations.h
        src/structs/data_type/Stations.cpp
        src/structs/data_type/Supply_Network.h
        src/structs/data_type/Supply_Network.cpp)