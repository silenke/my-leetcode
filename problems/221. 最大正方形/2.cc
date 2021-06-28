#include "..\..\leetcode.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        const int m = matrix.size();
        const int n = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(2, vector<int>(n));
        // dp[j]：以位置[i,j]为右下角的最大正方形的边长
        int curr = 0, prev = 1;
        for (int i = 0; i < m; i++) {
            curr ^= 1, prev ^= 1;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    dp[curr][j] = 0;
                }
                else {
                    if (i == 0 || j == 0) {
                        dp[curr][j] = 1;
                    }
                    else {
                        dp[curr][j] = min({dp[curr][j - 1], dp[prev][j], dp[prev][j - 1]}) + 1;
                    }
                    res = max(res, dp[curr][j]);
                }
            }
        }
        return res * res;
    }
};