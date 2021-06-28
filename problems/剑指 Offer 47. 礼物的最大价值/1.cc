#include "..\..\leetcode.h"

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {

        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) dp[i][j] = 0;
                else if (i == 0) dp[i][j] = dp[i][j - 1];
                else if (j == 0) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                dp[i][j] += grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};