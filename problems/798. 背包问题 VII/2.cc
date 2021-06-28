#include "..\..\leetcode.h"

class Solution {
public:
    /**
     * @param n: the money of you
     * @param prices: the price of rice[i]
     * @param weight: the weight of rice[i]
     * @param amounts: the amount of rice[i]
     * @return: the maximum weight
     */
    int backPackVII(int n, vector<int> &prices, vector<int> &weight, vector<int> &amounts) {
        // write your code here
        vector<int> dp(n + 1);
        // dp[j]：前i个物品装进容量为j的背包的最大价值
        for (int i = 0; i < prices.size(); i++) {
            int base = 1;
            while (amounts[i]) {
                int count = min(base, amounts[i]);
                int p = prices[i] * count;
                int w = weight[i] * count;
                for (int j = n; j >= p; j--) {
                    dp[j] = max(dp[j], dp[j - p] + w);
                }
                base *= 2;
                amounts[i] -= count;
            }
        }
        return dp[n];
    }
};