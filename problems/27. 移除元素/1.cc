#include "..\..\leetcode.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int r = 0;
        for (int n : nums) {
            if (n != val) nums[r++] = n;
        }
        return r;
    }
};