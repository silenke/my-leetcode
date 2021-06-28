#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> countBits(int num) {

        vector<int> dp(num + 1);
        // dp[i]：整数i中1的个数
        dp[0] = 0;
        for (int i = 1; i <= num; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};