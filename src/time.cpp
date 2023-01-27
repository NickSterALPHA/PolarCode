#include "PolarCode.h"
#include "Simulation.h"
#include <iostream>
#include <vector>
#include <cmath>
#include "matplotlibcpp.h"
#include <cstdlib>
#include <chrono>

namespace plt = matplotlibcpp;

std::vector<int> Generate_Vector(int length) {
    std::vector<int> res(length);
    for (int i = 0; i < length; i++) {
        res[i] = std::rand() % 2;
    }
    return res;
}

template <typename T>
void PrintVector(const std::vector<T>& v) {
    for(const auto& num : v) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------------\n";
}


int main() {
    std::vector<int> N = {16, 32, 64, 128, 256, 512};
    std::vector<int> k = {5, 16,  32, 64, 128, 256};
    std::vector<double> Time_SC, Time_SCL, Time_FastSCL;
    for (int i = 0; i < 6; i++) {
      std::vector<int> msg = Generate_Vector(k[i]); // generate random vec
      std::vector<int> crc_code = Get_CRC(msg, 8); // get crc
      msg.insert(msg.end(), crc_code.begin(), crc_code.end()); // insert crc

      // encode vector
      std::vector<int> msgFrozen = AddFrozen(msg, N[i]); // adding Frozen
      std::vector<std::vector<int>> Matrix1 = PolarTransform((int)log2(N[i]));
      std::vector<int> CodeWord = PolarEncoding(msgFrozen, Matrix1);
      
      //simulate channel
      BPSK(CodeWord);
      std::vector<double> ReceivedWord = AWGN(CodeWord, 1.3);

      std::vector<int> DecodedWord;

      auto begin = std::chrono::steady_clock::now();
      DecodedWord = SC_Decoding(ReceivedWord, k[i] + 8);
      auto end = std::chrono::steady_clock::now();
      Time_SC.push_back(std::chrono::duration<double>(end - begin).count());


      begin = std::chrono::steady_clock::now();
      std::vector<std::vector<int>> PosibleWords = SCList(ReceivedWord, k[i] + 8, 8);
      end = std::chrono::steady_clock::now();
      Time_SCL.push_back(std::chrono::duration<double>(end - begin).count());
      DecodedWord = Msg_Correct_CRC(PosibleWords, 8);
      

      begin = std::chrono::steady_clock::now();
      PosibleWords = Fast_SCL(ReceivedWord, k[i] + 8, 8);
      end = std::chrono::steady_clock::now();
      Time_FastSCL.push_back(std::chrono::duration<double>(end - begin).count());
      DecodedWord = Msg_Correct_CRC(PosibleWords, 8);
      
    }
    plt::plot(N, Time_FastSCL, {{"label", "Fast SCL"}});
    plt::plot(N, Time_SCL, {{"label", "SCL"}});
    plt::plot(N, Time_SC, {{"label", "SC"}});
    plt::xlabel("N");
    plt::ylabel("Time, sec");
    plt::legend();
    plt::show();
}