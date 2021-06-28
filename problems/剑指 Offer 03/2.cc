#include "..\..\leetcode.h"

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {

        const int n = nums.size();
        for (int x : nums) {
            if (x < 0) x += n;
            if (nums[x] < 0) return x;
            nums[x] -= n;
        }
        return -1;
    }
};