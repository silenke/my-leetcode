#include "..\..\leetcode.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int r = 0;  // 非零元素的右边界
        for (int& n : nums) {
            if (n != 0) swap(nums[r++], n);
        }
    }
};