#include "..\..\leetcode.h"

class Solution {
public:
    int numSquares(int n) {

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; ; j++) {
                int k = i - j * j;
                if (k < 0) break;
                dp[i] = min(dp[i], dp[k] + 1);
            }
        }
        return dp[n];
    }
};