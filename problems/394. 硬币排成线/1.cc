#include "..\..\leetcode.h"

class Solution {
public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here
        vector<bool> dp(n + 1);
        // dp[i]：剩余i个硬币时必胜
        for (int i = 1; i <= n; i++) {
            dp[i] = !dp[i - 1] || !dp[i - 2];
        }
        return dp[n];
    }
};