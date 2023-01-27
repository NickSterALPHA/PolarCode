#!/bin/bash
echo Updating packages 
sudo apt-get update 
echo Install requirements 
sudo apt install software-properties-common
sudo add-apt-repository ppa:deadsnakes/ppa
sudo apt install python3.9
sudo apt install python3-pip
pip install numpy
pip install matplotlib
sudo apt install libfltk1.3-dev


