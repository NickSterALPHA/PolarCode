cmake_minimum_required(VERSION 3.12)

project(PolarCodeDecoding)

add_library(PolarCodeLib 
            STATIC
            src/PolarCode/PolarCode.cpp)

add_library(SimulationLib 
            STATIC
            src/Simulation/Simulation.cpp)

target_include_directories(PolarCodeLib PUBLIC include)

target_include_directories(SimulationLib PUBLIC include)

find_package(Python3 COMPONENTS Intrepreter Development NumPy)

add_executable(Time src/time.cpp)
target_include_directories(Time PUBLIC ${Python3_INCLUDE_DIRS} include)
target_link_libraries(Time ${Python3_LIBRARIES} PolarCodeLib SimulationLib)

add_executable(Testing src/Testing.cpp)

target_link_libraries(Testing 
                       PRIVATE PolarCodeLib
                       PRIVATE SimulationLib)


find_package(FLTK REQUIRED NO_MODULE)
                        
add_executable(Graph src/Graph.cpp)

target_include_directories(Graph PUBLIC ${FLTK_INCLUDE_DIRS} ${Python3_INCLUDE_DIRS} include)
                        
target_link_libraries(Graph fltk  
                            ${Python3_LIBRARIES}
                            PolarCodeLib
                            SimulationLib)


add_executable(Unit_Test tests/Unit_Test.cpp)

target_include_directories(Unit_Test PUBLIC tests include)

target_link_libraries(Unit_Test PolarCodeLib SimulationLib)


