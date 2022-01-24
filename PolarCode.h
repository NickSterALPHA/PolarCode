#pragma once
#include <vector>

// operation for two matrices, which gives a new combined matrix
std::vector<std::vector<int>> KroneckerProduct(std::vector<std::vector<int>> first, 
                                        std::vector<std::vector<int>> second);

// function, which build new polar matrix size of 2^n x 2^n
std::vector<std::vector<int>> PolarTransform(int n);

//function takes Message and gives code Message
std::vector<int> PolarEncoding(const std::vector<int>& Message, 
                              const std::vector<std::vector<int>>& PolarMatrix);


