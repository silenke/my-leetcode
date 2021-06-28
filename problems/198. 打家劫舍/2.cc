#include "..\..\leetcode.h"

class Solution {
public:
    int rob(vector<int>& nums) {

        if (nums.empty()) return 0;

        int a = 0, b = nums[0];   // dp[i-2]，dp[i-1]
        for (int i = 2; i <= nums.size(); i++) {
            int c = max(a + nums[i - 1], b);
            a = b;
            b = c;
        }
        return b;
    }
};