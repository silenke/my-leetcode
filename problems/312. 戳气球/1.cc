#include "..\..\leetcode.h"

class Solution {
public:
    int maxCoins(vector<int>& nums) {

        nums.insert(nums.begin(), 1);
        nums.emplace_back(1);
        const int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        // dp[i][j]：[i,j]获得的最大硬币数
        for (int l = 3; l <= n; l++) {
            for (int i = 0; i + l - 1 < n; i++) {
                int j = i + l - 1;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = max(dp[i][j], nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};