#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> res(n, vector<int>(n));
        int i1 = 0, i2 = n - 1;
        int k = 1;
        while (i1 <= i2) {
            for (int j = i1; j <= i2; j++) {
                res[i1][j] = k++;
            }
            for (int i = i1 + 1; i <= i2; i++) {
                res[i][i2] = k++;
            }
            for (int j = i2 - 1; j >= i1; j--) {
                res[i2][j] = k++;
            }
            for (int i = i2 - 1; i > i1; i--) {
                res[i][i1] = k++;
            }
            i1++, i2--;
        }
        return res;
    }
};