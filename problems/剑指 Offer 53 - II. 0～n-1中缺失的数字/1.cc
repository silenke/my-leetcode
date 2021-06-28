#include "..\..\leetcode.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == mid) l = mid + 1;
            else r = mid;
        }
        return l < nums.size() ? nums[l] - 1 : l;
    }
};