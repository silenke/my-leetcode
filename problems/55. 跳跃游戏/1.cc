#include "..\..\leetcode.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {

        const int n = nums.size();
        vector<bool> dp(n, false);
        // dp[i]：可以到达位置i
        dp[0] = true;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && nums[j] >= i - j) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n - 1];
    }
};