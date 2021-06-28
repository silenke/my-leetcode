#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == target) break;
            else if (sum < target) l++;
            else r--;
        }
        return {nums[l], nums[r]};
    }
};