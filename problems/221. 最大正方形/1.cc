#include "..\..\leetcode.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        const int m = matrix.size();
        const int n = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        // dp[i][j]：以位置[i,j]为右下角的最大正方形的边长
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                }
                else {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    }
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }
};