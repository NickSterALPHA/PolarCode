#include "PolarCode.h"
#include "Simulation.h"
#include <iostream>
#include <vector>


template <typename T>
void PrintVector(const std::vector<T>& v) {
    for(const auto& num : v) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
int main() {
    std::vector<std::vector<int>> Matrix1 = PolarTransform(3);
    std::vector<int> message = {1, 1, 0, 0, 0, 1, 1, 1};
    std::cout << "Our Message : ";
    PrintVector<int>(message);
    std::vector<int> CodeWord = PolarEncoding(message, Matrix1);
    std::cout << "----------------------------------------------\n";
    std::cout << "CodeWord : ";
    PrintVector<int>(CodeWord);
    BPSK(CodeWord);
    std::cout << "------------------------------------------------\n";
    std::cout << "After Bpsk : ";
    PrintVector<int>(CodeWord);
    std::vector<double> ReceivedWord = AWGN(CodeWord, 2.0);
    std::cout << "-------------------------------------------------\n";
    std::cout << "After BPSK and AWGN : ";
    PrintVector<double>(ReceivedWord);
    return 0;
}