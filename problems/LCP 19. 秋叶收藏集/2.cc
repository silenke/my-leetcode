#include "..\..\leetcode.h"

class Solution {
public:
    int minimumOperations(string leaves) {

        vector<int> dp(3, INT_MAX);
        dp[0] = (leaves[0] == 'y');
        for (int i = 1; i < leaves.size(); i++) {
            char c = leaves[i];
            if (i > 1) dp[2] = min(dp[2], dp[1]) + (c == 'y');
            dp[1] = min(dp[1], dp[0]) + (c == 'r');
            dp[0] = dp[0] + (c == 'y');
        }
        return dp[2];
    }
};