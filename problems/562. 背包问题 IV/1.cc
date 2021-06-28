#include "..\..\leetcode.h"

class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackIV(vector<int> &nums, int target) {
        // write your code here
        vector<int> dp(target + 1);
        // dp[j]：前i种物品装满容量为j的背包的方案数
        dp[0] = 1;
        for (int n : nums) {
            for (int i = n; i <= target; i++) {
                dp[i] += dp[i - n];
            }
        }
        return dp[target];
    }
};