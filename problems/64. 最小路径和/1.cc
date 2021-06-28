#include "..\..\leetcode.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        // dp[i][j]：到达位置(i,j)的最小路径和
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                dp[i][j] += grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};