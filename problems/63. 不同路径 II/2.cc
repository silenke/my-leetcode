#include "..\..\leetcode.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        vector<int> dp(n);
        // dp[i][j]：到达位置(i,j)的路径数
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) dp[j] = 0;
                else if (i == 0 && j == 0) dp[j] = 1;
                else if (j > 0) dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};