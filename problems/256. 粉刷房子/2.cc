#include "..\..\leetcode.h"

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {

        const int n = costs.size();
        vector<vector<int>> dp(2, vector<int>(3));
        // dp[j]：前i个房子最后的房子粉刷成j颜色的最小花费
        int curr = 0, prev = 1;
        for (int i = 1; i <= n; i++) {
            curr ^= 1;
            prev ^= 1;
            for (int j = 0; j < 3; j++) {
                dp[curr][j] = INT_MAX;
                for (int k = 0; k < 3; k++) {
                    if (j == k) continue;
                    dp[curr][j] = min(dp[curr][j], dp[prev][k] + costs[i - 1][j]);
                }
            }
        }
        return min({dp[curr][0], dp[curr][1], dp[curr][2]});
    }
};