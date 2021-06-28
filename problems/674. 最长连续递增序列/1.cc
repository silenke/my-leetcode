#include "..\..\leetcode.h"

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

        const int n = nums.size();
        int res = 0;
        vector<int> dp(n, 1);
        // dp[i]：以位置i结尾的最长连续递增序列
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i - 1] < nums[i]) {
                dp[i] += dp[i - 1];
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};