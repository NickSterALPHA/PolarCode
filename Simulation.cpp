#include <vector>
#include <random>
#include "Simulation.h"

void BPSK(std::vector<int>& CodeWord) {
    for (auto& num : CodeWord) {
        if (num ==  0) {
            num = 1;
        } else if (num == 1) {
            num = -1;
        }
    }
}

std::vector<double> AWGN(const std::vector<int>& CodeWord, double stddev) {
    std::vector<double> result;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dist(0.0, 2.0);
    for (auto num : CodeWord) {
        result.push_back((double)num + dist(gen));
    }
    return result;
}