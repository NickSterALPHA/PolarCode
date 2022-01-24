#include "PolarCode.h"
#include "Simulation.h"
#include <iostream>
#include <vector>
#include <cmath>

template <typename T>
void PrintVector(const std::vector<T>& v) {
    for(const auto& num : v) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
int main() {
    std::vector<int> message = {1, 1, 1, 0, 1, 0}; // k bits
    std::cout << "Our Message : ";
    PrintVector<int>(message);
    std::cout << "----------------------------------------------\n";

    int k = (int)message.size(), N = (int)pow(2, (int)log2(k) + 1); // N = 2 ^ n
    message = AddFrozen(message, N);
    std::cout << "Message with frozen bytes : ";
    PrintVector<int>(message);
    std::cout << "----------------------------------------------\n";

    std::vector<std::vector<int>> Matrix1 = PolarTransform((int)log2(N));
    std::vector<int> CodeWord = PolarEncoding(message, Matrix1);
    std::cout << "CodeWord : ";
    PrintVector<int>(CodeWord);
    std::cout << "----------------------------------------------\n";


    BPSK(CodeWord);
    std::cout << "After Bpsk : ";
    PrintVector<int>(CodeWord);
    std::cout << "------------------------------------------------\n";


    std::vector<double> ReceivedWord = AWGN(CodeWord, 2.0);
    std::cout << "After BPSK and AWGN : ";
    PrintVector<double>(ReceivedWord);
    std::cout << "-------------------------------------------------\n";
    return 0;
}