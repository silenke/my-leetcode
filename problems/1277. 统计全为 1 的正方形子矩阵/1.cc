#include "..\..\leetcode.h"

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

        const int m = matrix.size();
        const int n = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(2, vector<int>(n));
        int curr = 0, prev = 1;
        for (int i = 0; i < m; i++) {
            curr ^= 1, prev ^= 1;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    dp[curr][j] = 0;
                }
                else {
                    if (i == 0 || j == 0) {
                        dp[curr][j] = 1;
                    }
                    else {
                        dp[curr][j] = min({dp[curr][j - 1], dp[prev][j], dp[prev][j - 1]}) + 1;
                    }
                    res += dp[curr][j];
                }
            }
        }
        return res;
    }
};