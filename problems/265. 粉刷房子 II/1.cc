#include "..\..\leetcode.h"

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {

        if (costs.empty()) return 0;

        int n = costs.size();
        int k = costs[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(k));
        // dp[i][j]：前i个房子最后粉刷成j颜色的最小花费
        for (int i = 1; i <= n; i++) {
            int min1 = INT_MAX, min2 = INT_MAX;
            for (int j = 0; j < k; j++) {
                if (dp[i - 1][j] < min1) {
                    min2 = min1;
                    min1 = dp[i - 1][j];
                }
                else if (dp[i - 1][j] < min2) {
                    min2 = dp[i - 1][j];
                }
            }
            for (int j = 0; j < k; j++) {
                if (dp[i - 1][j] != min1) {
                    dp[i][j] = min1 + costs[i - 1][j];
                }
                else {
                    dp[i][j] = min2 + costs[i - 1][j];
                }
            }
        }
        return *min_element(dp[n].begin(), dp[n].end());
    }
};