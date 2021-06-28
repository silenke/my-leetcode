#include "..\..\leetcode.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int i1 = 0, i2 = matrix.size() - 1;
        while (i1 < i2) {
            int n = i2 - i1;
            for (int i = 0; i < n; i++) {
                int tmp = matrix[i1][i1 + i];
                matrix[i1][i1 + i] = matrix[i2 - i][i1];
                matrix[i2 - i][i1] = matrix[i2][i2 - i];
                matrix[i2][i2 - i] = matrix[i1 + i][i2];
                matrix[i1 + i][i2] = tmp;
            }
            i1++; i2--;
        }
    }
};