#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "PolarCode.h"
#include "Simulation.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>
#include <cstdlib>

TEST_CASE("Check reliability seq ", "[ReliabilitySequenceForN]") {
    SECTION("N = 8") {
        int N = 8;
        std::vector<int> RelSeq = ReliabilitySequenceForN(N);
        REQUIRE(RelSeq == std::vector<int> {0, 1, 2, 4, 3, 5, 6, 7});
    }
    SECTION("N = 16") {
        int N = 16;
        std::vector<int> RelSeq = ReliabilitySequenceForN(N);
        REQUIRE(RelSeq == std::vector<int> {0, 1, 2, 4, 8, 3, 5, 9, 6, 10, 12, 7, 11, 13, 14, 15});
    }
}

TEST_CASE("Check to right adding frozen nodes", "[AddFrozen]") {
    SECTION("N = 8, k = 3") {
        int N = 8;
        std::vector<int> msg = {1, 1, 1};
        std::vector<int> Frozen_msg = AddFrozen(msg, N);
        REQUIRE(Frozen_msg == std::vector<int> {0, 0, 0, 0, 0, 1, 1, 1});
    }
    SECTION("N = 16, k = 10") {
        int N = 16;
        std::vector<int> msg = {1, 1, 0, 1, 0, 1, 1, 0, 0, 0};
        std::vector<int> Frozen_msg = AddFrozen(msg, N);
        REQUIRE(Frozen_msg == std::vector<int> {0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0});
    }
}

TEST_CASE("Polar Transform matrix", "[PolarTransform]") {
    SECTION("1 pow") {
        int n = 1;
        std::vector<std::vector<int>> G = PolarTransform(n);
        REQUIRE(G == std::vector<std::vector<int>> {{1, 0}, {1, 1}});
    }
    SECTION("2 pow") {
        int n = 2;
        std::vector<std::vector<int>> G = PolarTransform(n);
        REQUIRE(G == std::vector<std::vector<int>> {{1, 0, 0, 0}, {1, 1, 0, 0}, {1, 0, 1, 0}, {1, 1, 1, 1}});
    }
}


TEST_CASE("Polar encoding", "[PolarEncoding") {
    SECTION("1 Example encoding") {
        std::vector<int> message = {1, 0, 1, 1};
        std::vector<std::vector<int>> G = PolarTransform(2);
        REQUIRE(PolarEncoding(message, G) == std::vector<int> {1, 1, 0, 1});
    }
    SECTION("2 Example encoding") {
        std::vector<int> message = {0, 1};
        std::vector<std::vector<int>> G = PolarTransform(1);
        REQUIRE(PolarEncoding(message, G) == std::vector<int> {1, 1});
    }
}

TEST_CASE("BPSK test", "[BPSK]") {
    SECTION("Example of BPSK") {
        std::vector<int> enc_msg = {1, 0, 1, 0, 0, 0};
        BPSK(enc_msg);
        REQUIRE(enc_msg == std::vector<int> {-1, 1, -1, 1, 1, 1});
    }
}

TEST_CASE("Test for math func", "[sgn], [F], [G]") {
    SECTION("sgn testing") {
        REQUIRE(sgn(-5.0) == -1.0);
    }
    SECTION("F testing") {
        REQUIRE(F(0.24, 0.49) == 0.24);
    }
    SECTION("G testing") {
        REQUIRE(G(-0.14, 0.32, 0.24) == 0.2472);
    }
}

TEST_CASE("Test for vectors math func", "[FuncFVectors], [FuncGVectors], [SumTwoVectors]") {
    SECTION("FuncFVectors testing") {
        std::vector<double> vec1 = {0.24, 0.34, -0.21, 0.25};
        std::vector<double> vec2 = {-0.23, 0.15, -0.13, 0.26};
        REQUIRE(FuncFVectors(vec1, vec2) == std::vector<double> {-0.23, 0.15, 0.13, 0.25});
    }
    SECTION("FuncGVectors testing") {
        std::vector<double> vec1 = {0.21, 0.11, -0.51, 0.15};
        std::vector<double> vec2 = {-0.22, 0.15, -0.23, 0.16};
        std::vector<double> vec3 = {1, 0, 1, 0};
        REQUIRE(FuncGVectors(vec1, vec2, vec3) == std::vector<double> {-0.43, 0.26, 0.28, 0.31});
    }
    SECTION("SumTwoVectors testing") {
        std::vector<int> first = {1, 0};
        std::vector<int> second = {1, 1};
        REQUIRE(SumTwoVectors(first, second) == std::vector<int> {0, 1, 1, 1});
    }
}


TEST_CASE("Left and Right shifting", "[LShiftVector], [RShiftVector]") {
    SECTION("LeftShift example") {
        std::vector<int> msg = {1, 0, 0, 1, 1, 1};
        LShiftVector(msg);
        REQUIRE(msg == std::vector<int> {0, 0, 1, 1, 1, 0});
    }
    SECTION("RightShift example") {
        std::vector<int> msg = {1, 0, 0, 1, 1, 1};
        RShiftVector(msg);
        REQUIRE(msg == std::vector<int> {0, 1, 0, 0, 1, 1});
    }
}

TEST_CASE("Left and Right shifting by any pos", "[LShiftVectorOffset], [RShiftVectorOffset]") {
    SECTION("LeftShiftOffset example") {
        std::vector<int> msg = {1, 0, 0, 1, 1, 1};
        msg = LShiftVectorOffset(msg, 3);
        REQUIRE(msg == std::vector<int> {1, 1, 1, 0, 0, 0});
    }
    SECTION("RightShiftOffset example") {
        std::vector<int> msg = {1, 0, 0, 1, 1, 1};
        msg = LShiftVectorOffset(msg, 2);
        REQUIRE(msg == std::vector<int> {0, 1, 1, 1, 0, 0});
    }
}

TEST_CASE("XOR two vectors", "[operator^]") {
    SECTION("size1 == size 2") {
        std::vector<int> vec1 = {1, 0, 0, 1, 1, 1};
        std::vector<int> vec2 = {1, 0, 0, 0, 1, 0};
        REQUIRE((vec1 ^ vec2) == std::vector<int> {0, 0, 0, 1, 0, 1});
    }
    SECTION("size1 < size2") {
        std::vector<int> vec1 = {0, 1, 0};
        std::vector<int> vec2 = {1, 1, 0, 1, 0};
        REQUIRE((vec1 ^ vec2) == std::vector<int> {1, 1, 0, 0, 0});
    }
}

TEST_CASE("Сalculate CRC", "[Get_CRC]") {
    SECTION("CRC size = 8") {
        int CRC_size = 8;
        std::vector<int> msg = {0, 1, 0, 1, 1, 1, 0, 1};
        REQUIRE(Get_CRC(msg, CRC_size) == std::vector<int> {1, 0, 0, 1, 0, 1, 0, 0});
    }
    SECTION("CRC size = 16") {
        int CRC_size = 16;
        std::vector<int> msg = {1, 1, 1, 0, 0, 0, 1, 0};
        REQUIRE(Get_CRC(msg, CRC_size) == std::vector<int> {1, 1, 0, 1, 1, 0, 1, 1, 
                                                            0, 0, 1, 1, 1, 1, 0, 0});
    }
    SECTION("CRC size = 32") {
        int CRC_size = 32;
        std::vector<int> msg = {1, 0, 1, 0, 1, 0, 0, 0};
        REQUIRE(Get_CRC(msg, CRC_size) == std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0,
                                                            0, 0, 0, 0, 0, 0, 0, 0,
                                                            0, 1, 0, 0, 0, 1, 1, 1, 
                                                            0, 0, 0, 1, 1, 0, 0, 0});
    }
}


TEST_CASE("Find Num Errors", "[NumError") {
    SECTION("size 1 = size 2") {
        std::vector<int> vec1 = {1, 0, 1, 1};
        std::vector<int> vec2 = {0, 1, 1, 1};
        REQUIRE(NumErrors(vec1, vec2) == 2);
    }
    SECTION("size 1 < size 2") {
        std::vector<int> vec1 = {1, 0, 1, 0, 0};
        std::vector<int> vec2 = {0, 0, 1, 0, 0, 1, 1, 1};
        REQUIRE(NumErrors(vec1, vec2) == 1);
    }
}