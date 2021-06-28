#include "..\..\leetcode.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int r = 0;  // 0的右边界
        int l = nums.size();    // 2的左边界
        int i = 0;
        while (i < l) {
            if (nums[i] == 0) swap(nums[r++], nums[i++]);
            else if (nums[i] == 1) i++;
            else swap(nums[i], nums[--l]);
        }
    }
};