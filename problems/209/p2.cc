#include "..\..\leetcode.h"

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int res = INT_MAX;
        int l = 0;
        int sum = 0;
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (sum >= target) {
                res = min(res, r - l + 1);
                sum -= nums[l++];
            }
        }
        return res != INT_MAX ? res : 0;
    }
};