#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {

        int r = 0;
        for (int& n : nums) {
            if (n & 1) {
                swap(nums[r++], n);
            }
        }
        return nums;
    }
};