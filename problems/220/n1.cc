#include "..\..\leetcode.h"

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

        set<long> s;
        for (int i = 0; i < nums.size(); i++) {
            auto it = s.lower_bound(static_cast<long>(nums[i]) - t);
            if (it != s.end() && *it <= static_cast<long>(nums[i]) + t) return true;
            s.insert(nums[i]);
            if (s.size() > k) s.erase(nums[i - k]);
        }
        return false;
    }
};