#include "..\..\leetcode.h"

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        int l = 0;  // 窗口左边界，窗口是[l,r]，初始时l=0，r=-1，窗口大小为0
        int sum = 0;
        int res = INT_MAX;
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (sum - nums[l] >= s) {
                sum -= nums[l++];
            }
            if (sum >= s) {
                res = min(res, r - l + 1);
            }
        }
        return res < INT_MAX ? res : 0;
    }
};