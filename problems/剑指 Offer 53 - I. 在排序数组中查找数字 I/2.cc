#include "..\..\leetcode.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {

        auto l = upper_bound(nums.begin(), nums.end(), target - 1);
        auto r = upper_bound(l, nums.end(), target);
        return r - l;
    }
};