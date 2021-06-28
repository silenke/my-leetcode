#include "..\..\leetcode.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        const int m = grid.size();
        const int n = grid[0].size();
        vector<int> dp(n, INT_MAX);
        // dp[j]：到达位置(i,j)的最小路径和
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[j] = grid[i][j];
                    continue;
                }
                if (j > 0) dp[j] = min(dp[j], dp[j - 1]);
                dp[j] += grid[i][j];
            }
        }
        return dp[n - 1];
    }
};