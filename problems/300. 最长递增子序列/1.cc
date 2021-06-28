#include "..\..\leetcode.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        const int n = nums.size();
        int res = 0;
        vector<int> dp(n);
        // dp[i]：以位置i结尾的LIS长度
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            res = max(res, ++dp[i]);
        }
        return res;
    }
};