#pragma once
#include <vector>


// binary phase-shift keying using for CodeWord
void BPSK(std::vector<int>& CodeWord);

// function is sumalating Additive white Gaussian noise, returns a changed nums of codeword
std::vector<double> AWGN(const std::vector<int>& CodeWord, double stddev);