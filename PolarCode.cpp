#include "PolarCode.h"
#include <vector>
#include <string>

std::vector<std::vector<int>> KroneckerProduct(std::vector<std::vector<int>> first, 
                                        std::vector<std::vector<int>> second) {

    std::vector<std::vector<int>> result;
    for (int i = 0; i < first.size(); i++) {
        int num1 = first[i][0];
        int num2 = first[i][1];
        for (int k = 0; k < second.size(); k++) {
            std::vector<int> line1 = second[k];
            for (int l = 0; l < line1.size(); l++) line1[l] *= num1;
            std::vector<int> line2 = second[k];
            for (int l = 0; l < line2.size(); l++) line2[l] *= num2;
            std::vector<int> final_line;
            final_line.insert(final_line.end(), line1.begin(), line1.end());
            final_line.insert(final_line.end(), line2.begin(), line2.end());
            result.push_back(final_line);
        }
    }
    return result;
}

std::vector<std::vector<int>> PolarTransform(int n) { 
    std::vector<std::vector<int>> begin{{1, 0}, {1, 1}}; 
    if (n == 1) {
        return begin;
    }
    return KroneckerProduct(begin, PolarTransform(n - 1));
}

std::vector<int> PolarEncoding(const std::vector<int>& Message, 
                              const std::vector<std::vector<int>>& PolarMatrix) {
    std::vector<int> result;
    int columns = PolarMatrix[0].size();
    for (int i = 0; i < columns; i++) {
        int c = 0;
        for (int j = 0; j < PolarMatrix.size(); j++) {
            c = c ^ (Message[j] * PolarMatrix[j][i]);
        }
        result.push_back(c);
    }
    return result;
}