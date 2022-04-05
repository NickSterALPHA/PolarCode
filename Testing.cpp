#include "PolarCode.h"
#include "Simulation.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

template <typename T>
void PrintVector(const std::vector<T>& v) {
    for(const auto& num : v) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------------\n";
}
int main() {
    std::vector<int> message = {0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0}; // k bits
    std::cout << "Our Message : ";
    PrintVector<int>(message);


    int k = (int)message.size(), N = (int)pow(2, (int)log2(k) + 2); // N = 2 ^ n
    std::vector<int> messageFrozen = AddFrozen(message, N);
    std::cout << "Message with frozen bytes : ";
    PrintVector<int>(messageFrozen);

    std::vector<std::vector<int>> Matrix1 = PolarTransform((int)log2(N));
    std::vector<int> CodeWord = PolarEncoding(messageFrozen, Matrix1);
    std::cout << "CodeWord : ";
    PrintVector<int>(CodeWord);


    BPSK(CodeWord);
    std::cout << "After Bpsk : ";
    PrintVector<int>(CodeWord);


    std::vector<double> ReceivedWord = AWGN(CodeWord, 1.0);
    std::cout << "After BPSK and AWGN : ";
    PrintVector<double>(ReceivedWord);

    auto begin = std::chrono::steady_clock::now();
    std::vector<int> SC_msg = SC_Decoding(ReceivedWord, k);
    auto end = std::chrono::steady_clock::now();
    std::cout << "Result of SC decoding : ";
    PrintVector<int>(SC_msg);

    if (SC_msg == message) {
        std::cout << "The decoded message is identical to the initial message"<< std::endl;
    } else {
        int count_errors = 0;
        for(int i = 0; i < SC_msg.size(); i++) {
            if (SC_msg[i] != message[i]) {
                count_errors++;
            }
        }
        std::cout << "The decoded message does not match the initial message" << std::endl;
        std::cout << "There are " << count_errors << " errors" << std::endl;
    }

    auto timeSC = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time of SC algortihm equal " << timeSC.count() << " milliseconds" << std::endl;
    return 0;
}