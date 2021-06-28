#include "..\..\leetcode.h"

class Solution {
public:
    int rob(vector<int>& nums) {

        if (nums.size() == 1) return nums[0];

        function<int(int)> rob = [&](int l) {
            int a = 0, b = nums[l]; // dp[i-2]，dp[i-1]
            for (int i = 2; i < nums.size(); i++) {
                int c = max(a + nums[l + i - 1], b);
                a = b;
                b = c;
            }
            return b;
        };
        return max(rob(0), rob(1));
    }
};