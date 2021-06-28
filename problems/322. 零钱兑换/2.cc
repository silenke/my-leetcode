#include "..\..\leetcode.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, amount + 1);
        // dp[i]：凑成i所需的最小硬币数，amount+1：凑不成i
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int c : coins) {
                int j = i - c;
                if (j >= 0) dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[amount] <= amount ? dp[amount] : -1;
    }
};