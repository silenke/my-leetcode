#include "..\..\leetcode.h"

class Solution {
public:
    /**
     * @param n: the money you have
     * @return: the minimum money you have to give
     */
    int backPackX(int n) {
        // write your code here
        vector<int> dp(n + 1);
        // dp[j]：前i种物品装进容量为j的背包获得的最大价值
        for (int p : {150, 250, 350}) {
            for (int j = p; j <= n; j++) {
                dp[j] = max(dp[j], dp[j - p] + p);
            }
        }
        return n - dp[n];
    }
};