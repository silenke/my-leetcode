#include "..\..\leetcode.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        const int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(5));
        // dp[i][j]：前i天结束时处在状态j的最大获利
        dp[0][1] = 0;
        fill(dp[0].begin() + 1, dp[0].end(), INT_MIN);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 5; j++) {
                if (j & 1) {
                    dp[i][j] = dp[i - 1][j - 1];
                    if (i >= 2 && dp[i - 1][j] != INT_MIN) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j] + prices[i - 1] - prices[i - 2]);
                    }
                }
                else {
                     dp[i][j] = dp[i - 1][j];
                    if (j >= 1 && i >= 2 && dp[i - 1][j - 1] != INT_MIN) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + prices[i - 1] - prices[i - 2]);
                    }
                }
            }
        }
        return max({dp[n][0], dp[n][2], dp[n][4]});
    }
};