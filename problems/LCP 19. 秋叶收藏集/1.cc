#include "..\..\leetcode.h"

class Solution {
public:
    int minimumOperations(string leaves) {

        const int n = leaves.size();
        vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
        for (int i = 0; i < n; i++) {
            char c = leaves[i];
            if (i > 0) dp[i][0] = dp[i - 1][0] + (c == 'y');
            else dp[i][0] = (c == 'y');
            if (i > 0) dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (c == 'r');
            if (i > 1) dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + (c == 'y');
        }
        return dp[n - 1][2];
    }
};