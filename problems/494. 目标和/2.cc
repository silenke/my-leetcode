#include "..\..\leetcode.h"

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {

        const int n = nums.size();
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < abs(S)) return 0;

        const int maxN = sum * 2;
        vector<vector<int>> dp(2, vector<int>(maxN + 1, 0));
        int curr = 0, prev = 1;
        dp[curr][sum] = 1;
        for (int num : nums) {
            curr ^= 1;
            prev ^= 1;
            // for (int j = 0; j <= maxN; j++) {
            //     if (j - num >= 0) dp[curr][j] = dp[prev][j - num];
            //     if (j + num <= maxN) dp[curr][j] += dp[prev][j + num];
            // }
            for (int j = num; j <= maxN - num; j++) {
                dp[curr][j + num] = dp[prev][j];
                dp[curr][j - num] += dp[prev][j];
            }
        }
        return dp[curr][S + sum];
    }
};