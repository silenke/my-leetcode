#include "..\..\leetcode.h"

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        const int n = prices.size();
        if (k > n / 2) {
            int res = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    res += (prices[i] - prices[i - 1]);
                }
            }
            return res;
        }

        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1));
        // dp[i][j]：前i天结束时为状态j的最大获利
        dp[0][0] = 0;
        fill(dp[0].begin() + 1, dp[0].end(), INT_MIN);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 2 * k + 1; j += 2) {
                dp[i][j] = dp[i - 1][j];
                if (i >= 2 && j >= 1 && dp[i - 1][j - 1] != INT_MIN) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + prices[i - 1] - prices[i - 2]);
                }
            }
            for (int j = 1; j < 2 * k; j += 2) {
                dp[i][j] = dp[i - 1][j - 1];
                if (i >= 2 && dp[i - 1][j] != INT_MIN) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + prices[i - 1] - prices[i - 2]);
                }
            }
        }
        int res = 0;
        for (int j = 0; j < 2 * k + 1; j += 2) {
            res = max(res, dp[n][j]);
        }
        return res;
    }
};