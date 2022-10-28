cmake_minimum_required(VERSION 3.8)

project(PolarCodeDecoding)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR ${CMAKE_SOURCE_DIR}/lib/SFML/lib/cmake/SFML)


find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

if (SFML_FOUND)
    add_executable(MainAppEXE ${PROJECT_SOURCE_DIR}/src/MainApp.cpp)
    target_include_directories(MainAppEXE PUBLIC ${PROJECT_SOURCE_DIR}/lib/SFML/include/SFML) 
    target_link_libraries(MainAppEXE PRIVATE sfml-graphics sfml-audio)
endif (SFML_FOUND)

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
