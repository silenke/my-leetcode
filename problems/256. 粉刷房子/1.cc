#include "..\..\leetcode.h"

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {

        const int n = costs.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, INT_MAX));
        // dp[i][j]：前i个房子最后的房子粉刷成j颜色的最小花费
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (j == k) continue;
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + costs[i - 1][j]);
                }
            }
        }
        return min({dp[n][0], dp[n][1], dp[n][2]});
    }
};