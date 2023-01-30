
#pragma once
#include <vector>
#include <map>


using vector3d_double = std::vector<std::vector<std::vector<double>>>;

// operation for two matrices, which gives a new combined matrix
std::vector<std::vector<int>> KroneckerProduct(const std::vector<std::vector<int>>& first, 
                                       const std::vector<std::vector<int>>& second);

// function, which build new polar matrix size of 2^n x 2^n
std::vector<std::vector<int>> PolarTransform(int n);

//function takes Message and gives code Message
std::vector<int> PolarEncoding(const std::vector<int>& Message, 
                              const std::vector<std::vector<int>>& PolarMatrix);

//function gives sequences of realibitiy channel < N
std::vector<int> ReliabilitySequenceForN(const int& N);

//Gives new message with frozen bytes
std::vector<int> AddFrozen(const std::vector<int>& Message, const int& N);

//Function "sign" in math, sign(x) = -1 if x < 0, sign(x) = 1 if x > 0, sign(x) = 0 if x = 0
double sgn(const double& num);

// Function F(a, b) "minsum" for 2 num
double F(const double& a, const double& b);

//Function G(a, b, U) for 3 num
double G(const double& a, const double& b, const double& c);

//Function F(a,b) "minsum" for vectors, return vector {F(first[1], second[1]), F(first[2], second[2]) ...} 
std::vector<double> FuncFVectors(const std::vector<double>& first, const std::vector<double>& second); 

//Function G(a,b,U)  for vectors, return vector {G(first[1], second[1], third[1]), G ...} 
std::vector<double> FuncGVectors(const std::vector<double>& first, const std::vector<double>& second, 
                                 const std::vector<double>& third);

// takes vectors : v1 and v2 , then return [v1 xor v2, v2]
std::vector<int> SumTwoVectors(const std::vector<int>& first, 
                                const std::vector<int>& second);
                                  
// Decoding of Polar code with SC method
std::vector<int> SC_Decoding(const std::vector<double>& CodeWord, const int& k);

//Generate Polynom of degree CRC_size
std::vector<int> GeneratePolynom(int CRC_size);

// Generate all posible vectors with values from 0 to 255 in binary representation
// input args : CRC_size - size of CRC could be 8, 16, 32
std::vector<std::vector<int>> GenerateVectors(int CRC_size);

// left shift vector by one position
void LShiftVector(std::vector<int> &vec);

// left shift copy of vector by offset and return it
std::vector<int> LShiftVectorOffset(std::vector<int> vec, int offset);

// right shift vector by one position
void RShiftVector(std::vector<int> &vec);

// left shift copy of vector by offset and return it
std::vector<int> RShiftVectorOffset(std::vector<int> vec, int offset); 

// xor two bytes(vectors)
std::vector<int> operator^ (const std::vector<int>& first,const std::vector<int>& second);

// table with finished CRC results
std::map<std::vector<int>, std::vector<int>> GenerateTable(const std::vector<int>& Gpolynom, 
                                                           int CRC_size);

// return crc - code for message 
std::vector<int> Get_CRC(std::vector<int> message, int CRC_size);

// check: CRC-code corresponds to this message ? 
bool Check_CRC(std::vector<int> message, int CRC_size);

// SC List Decoder, which returns decod_num possible CodeWords
std::vector<std::vector<int>> SCList(const std::vector<double>& CodeWord,const int& k,const int& decod_num);

// Choose Message with correct CRC - code
std::vector<int> Msg_Correct_CRC(const std::vector<std::vector<int>>& PosibleWords, const int& CRC_size);

// fast SCL decoder
std::vector<std::vector<int>> Fast_SCL(const std::vector<double>& CodeWord, const int& k, const int& decod_num);


// gives massive with information, bit is frozen or not ? 
// it gives info, 
// if i bit is frozen <=> res[i] = 1
// if i bit is not frozen <=> res[i] = 0
std::vector<int> IsFrozenNode(const std::vector<int>& RelSeq, const int& k);

// true - if vec[left] .. vec[right - 1] == element
// false - if vec[j] != element
bool AllEquals(const std::vector<int>& vec, const int& left, const int& right, const int& element);

// index of least reliable bits  (mod length_node)
std::vector<int> least_reliable_bit(const vector3d_double& L, const int& depth, const int& length_node,  
                                const int& layer, const int& node, const int& num_least_bits);

//find num errors between message and decoded word
int NumErrors(const std::vector<int>& Msg, const std::vector<int>& DecodWord);

std::vector<std::vector<int>> Upgrade_Fast_SCL(const std::vector<double>& CodeWord,const int& k, const int& decod_num);







