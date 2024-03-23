cmake_minimum_required(VERSION 3.26.4)
project(projeto_1)

set(CMAKE_CXX_STANDARD 17)

file(COPY src/Data/Project1DataSetSmall DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY src/Data/Project1LargeDataSet DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

include_directories(src/structs/aux_structs)
include_directories(src/structs/data_type)
include_directories(src)

add_executable(project_2 src/main.cpp
        src/structs/aux_structs/Graph.h
        src/structs/aux_structs/MutablePriorityQueue.h
        src/structs/data_type/Reservoir.h
        src/structs/data_type/Reservoir.cpp
        src/structs/data_type/City.h
        src/structs/data_type/City.cpp
        src/structs/data_type/Stations.h
        src/structs/data_type/Stations.cpp
        src/structs/data_type/Supply_Network.h
        src/structs/data_type/Supply_Network.cpp
        src/menu.cpp
        src/menu.h
        src/functions.h
        src/functions.cpp)