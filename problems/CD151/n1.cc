#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> print(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> res;
        int i1 = 0, j1 = 0;
        int i2 = 0, j2 = 0;
        bool up = true;
        while (j1 < n) {
            int k = i1 - i2 + 1;
            for (int i = 0; i < k; i++) {
                if (up) res.emplace_back(matrix[i1 - i][j1 + i]);
                else res.emplace_back(matrix[i2 + i][j2 - i]);
            }
            if (i1 < m - 1) i1++;
            else j1++;
            if (j2 < n - 1) j2++;
            else i2++;
            up ^= 1;
        }
        return res;
    }
};