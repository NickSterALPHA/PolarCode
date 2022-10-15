#pragma once
#include <vector>
#include <map>


// operation for two matrices, which gives a new combined matrix
std::vector<std::vector<int>> KroneckerProduct(std::vector<std::vector<int>> first, 
                                        std::vector<std::vector<int>> second);

// function, which build new polar matrix size of 2^n x 2^n
std::vector<std::vector<int>> PolarTransform(int n);

//function takes Message and gives code Message
std::vector<int> PolarEncoding(const std::vector<int>& Message, 
                              const std::vector<std::vector<int>>& PolarMatrix);

//function gives sequences of realibitiy channel < N
std::vector<int> ReliabilitySequenceForN(int N);

//Gives new message with frozen bytes
std::vector<int> AddFrozen(std::vector<int> Message, int N);

//Function "sign" in math, sign(x) = -1 if x < 0, sign(x) = 1 if x > 0, sign(x) = 0 if x = 0
double sgn(double num);

// Function F(a, b) "minsum" for 2 num
double F(double a, double b);

//Function G(a, b, U) for 3 num
double G(double a, double b, double c);

//Function F(a,b) "minsum" for vectors, return vector {F(first[1], second[1]), F(first[2], second[2]) ...} 
std::vector<double> FuncFVectors(std::vector<double> first, std::vector<double> second); 

//Function G(a,b,U)  for vectors, return vector {G(first[1], second[1], third[1]), G ...} 
std::vector<double> FuncGVectors(std::vector<double> first, std::vector<double> second, 
                                 std::vector<double> third);

// takes vectors : v1 and v2 , then return [v1 xor v2, v2]
std::vector<int> SumTwoVectors(std::vector<int> first, 
                                  std::vector<int> second);
                                  
// Decoding of Polar code with SC method
std::vector<int> SC_Decoding(std::vector<double> CodeWord, int k);

// Generate all posible vectors with values from 0 to 255 in binary representation
std::vector<std::vector<int>> GenerateVectors();

// left shift vector by one position
void LShiftVector(std::vector<int> &vec);

// xor two bytes(vectors)
std::vector<int> operator^ (const std::vector<int>& first,const std::vector<int>& second);

// table with finished xor results
std::map<std::vector<int>, std::vector<int>> GenerateTable(std::vector<int> Gpolynom);

// return crc - code for message 
std::vector<int> Get_CRC_8(std::vector<int> message);

// check: CRC-code corresponds to this message ? 
bool Check_CRC_8(std::vector<int> message);

// SC List Decoder, which returns 8 possible CodeWords
std::vector<std::vector<int>> SCList_8(std::vector<double> CodeWord, int k, int decod_num);


// Choose Message with correct CRC - code
std::vector<int> Msg_Correct_CRC(const std::vector<std::vector<int>>& PosibleWords);







