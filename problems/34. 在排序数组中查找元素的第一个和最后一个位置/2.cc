#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        auto [l, r] = equal_range(nums.begin(), nums.end(), target);
        if (l == r) return {-1, -1};
        return {static_cast<int>(l - nums.begin()), static_cast<int>(r - nums.begin() - 1)};
    }
};