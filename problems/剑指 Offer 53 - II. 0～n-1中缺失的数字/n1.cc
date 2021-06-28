#include "..\..\leetcode.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int l = 0, r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] != m) r = m;
            else l = m + 1;
        }
        return l;
    }
};