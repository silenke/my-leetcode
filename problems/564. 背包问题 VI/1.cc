#include "..\..\leetcode.h"

class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackVI(vector<int> &nums, int target) {
        // write your code here
        vector<int> dp(target + 1);
        // dp[i]：拼出整数i的方法数
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int n : nums) {
                if (i >= n) dp[i] += dp[i - n];
            }
        }
        return dp[target];
    }
};