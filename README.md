# PolarCode
Implementation of polar code decoding algorithms

# Struct of Project

PolarCode.h - list of function, which helps to decode/encode msg
PolarCode.cpp - implementation of function from PolarCode.h

Simulation.h - list of function, which helps to simulate channel 
Simulation.cpp - implementation of function from Simulation.h

Testing.cpp - main file 

# How to compile ???
1) You need to generate objects files

clang -c PolarCode.cpp

clang -c Simulation.cpp

clang -c Testing.cpp

2) You need to link objects files

clang PolarCode.o Simulation.o Testing.o -o Testing.exe

# How to run ????

You need to open CMD and open file "Testing.exe"