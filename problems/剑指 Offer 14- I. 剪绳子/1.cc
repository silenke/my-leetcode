#include "..\..\leetcode.h"

class Solution {
public:
    int cuttingRope(int n) {

        vector<int> dp(n + 1);  // dp[i]：整数i的最大乘积
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                dp[i] = max(dp[i], j * max(i - j, dp[i - j]));
            }
        }
        return dp[n];
    }
};