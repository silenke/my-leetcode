#include "..\..\leetcode.h"

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {

        const int m = matrix.size();
        if (m == 0) return false;
        const int n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (target == matrix[i][j]) return true;
            if (target < matrix[i][j]) j--;
            else i++;
        }
        return false;
    }
};