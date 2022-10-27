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
    std::vector<int> message = {0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1}; // k bits
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


    std::vector<double> ReceivedWord = AWGN(CodeWord, 1.4);
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


    std::cout << "Prepare for algorutithm SC List" << std::endl;
    std::cout << "Current message: " << std::endl;
    PrintVector<int>(message);
    int size_of_message = message.size();

    std::cout << "CRC - Code for message: " << std::endl;
    std::vector<int> crc_code = Get_CRC_8(message);
    PrintVector<int>(crc_code);
    std::cout << "Message with CRC - Code " << std::endl;
    std::vector<int> msg_crc(message);
    msg_crc.insert(msg_crc.end(), crc_code.begin(), crc_code.end());
    PrintVector<int>(msg_crc);
    


    k = (int)msg_crc.size(); N = (int)pow(2, (int)log2(k) + 2); // N = 2 ^ n
    messageFrozen = AddFrozen(msg_crc, N);
    std::cout << "Message with frozen bytes : ";
    PrintVector<int>(messageFrozen);

    Matrix1 = PolarTransform((int)log2(N));
    CodeWord = PolarEncoding(messageFrozen, Matrix1);
    std::cout << "CodeWord : ";
    PrintVector<int>(CodeWord);


    BPSK(CodeWord);
    std::cout << "After Bpsk : ";
    PrintVector<int>(CodeWord);


    ReceivedWord = AWGN(CodeWord, 1.4);
    std::cout << "After BPSK and AWGN : ";
    PrintVector<double>(ReceivedWord);

    begin = std::chrono::steady_clock::now();
    std::vector<std::vector<int>> PosibleWords = SCList(ReceivedWord, k, 20);
    end = std::chrono::steady_clock::now();

    timeSC = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time of SCL algortihm equal " << timeSC.count() << " milliseconds" << std::endl;

    for (int i = 0; i < PosibleWords.size(); i++) {
        for(auto num : PosibleWords[i]) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "----------------------------------------------\n";

    std::cout << "There was choosen only one MSG WITH CRC: ";
    std::vector<int> Msg_CRC_SCL_Decoding = Msg_Correct_CRC(PosibleWords);
    std::vector<int> Msg_SCL_Decoding;
    Msg_SCL_Decoding.insert(Msg_SCL_Decoding.begin(), Msg_CRC_SCL_Decoding.begin(), 
                                                      Msg_CRC_SCL_Decoding.begin() + size_of_message);

    PrintVector<int>(Msg_SCL_Decoding);

    if (Msg_SCL_Decoding == message) {
         std::cout << "The decoded message is identical to the initial message"<< std::endl;
    } else {
        int count_errors = 0;
        for(int i = 0; i < Msg_SCL_Decoding.size(); i++) {
            if (Msg_SCL_Decoding[i] != message[i]) {
                count_errors++;
            }
        }
        std::cout << "The decoded message does not match the initial message" << std::endl;
        std::cout << "There are " << count_errors << " errors" << std::endl;
    }








    
    return 0;
}