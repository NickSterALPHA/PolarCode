cmake_minimum_required(VERSION 3.8)

project(PolarCodeDecoding)

add_library(PolarCodeLib 
            STATIC
            src/PolarCode/PolarCode.cpp)

add_library(SimulationLib 
            STATIC
            src/Simulation/Simulation.cpp)

target_include_directories(PolarCodeLib
                           PUBLIC
                           ${PROJECT_SOURCE_DIR}/include)

target_include_directories(SimulationLib
                           PUBLIC
                           ${PROJECT_SOURCE_DIR}/include)

add_executable(TestingEXE ${PROJECT_SOURCE_DIR}/src/Testing.cpp)

target_link_libraries(TestingEXE 
                       PRIVATE PolarCodeLib
                       PRIVATE SimulationLib)