#include "..\..\leetcode.h"

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        S = abs(S);
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < S || (S + sum) & 1) return 0;

        const int target = (S + sum) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int n : nums) {
            vector<int> tmp(dp);
            for (int j = 0; j <= target - n; j++) {
                tmp[j + n] += dp[j];
            }
            dp.swap(tmp);
        }
        return dp[target];
    }
};