#include "..\..\leetcode.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {

        auto [l, r] = equal_range(nums.begin(), nums.end(), target);
        return r - l;
    }
};