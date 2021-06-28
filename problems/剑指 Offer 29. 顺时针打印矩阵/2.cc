#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        const int m = matrix.size();
        if (m == 0) return {};
        const int n = matrix[0].size();

        vector<int> res(m * n);
        int k = 0;
        int i1 = 0, i2 = m - 1;
        int j1 = 0, j2 = n - 1;
        while (true) {
            for (int j = j1; j <= j2; j++) res[k++] = matrix[i1][j];
            if (++i1 > i2) break;
            for (int i = i1; i <= i2; i++) res[k++] = matrix[i][j2];
            if (--j2 < j1) break;
            for (int j = j2; j >= j1; j--) res[k++] = matrix[i2][j];
            if (--i2 < i1) break;
            for (int i = i2; i >= i1; i--) res[k++] = matrix[i][j1];
            if (++j1 > j2) break;
        }
        return res;
    }
};