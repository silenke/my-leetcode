#include "..\..\leetcode.h"

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {

        const int m = grid.size();
        const int n = grid[0].size();
        vector<int> dp(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0) dp[j] = max(dp[j], dp[j - 1]);
                dp[j] += grid[i][j];
            }
        }
        return dp[n - 1];
    }
};