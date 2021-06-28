#include "..\..\leetcode.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, INT_MAX);
        // dp[i]：凑成i所需的最小硬币数，INT_MAX：凑不成i
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int c : coins) {
                int j = i - c;
                if (j >= 0 && dp[j] < INT_MAX) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};