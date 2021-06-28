#include "..\..\leetcode.h"

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

        unordered_map<long, int> map;
        for (int i = 0; i < nums.size(); i++) {

            long id = getId(t, nums[i]);
            if (map.find(id) != map.end()) return true;

            auto l = map.find(id - 1);
            if (l != map.end() && static_cast<long>(nums[i]) - l->second <= t) return true;

            auto r = map.find(id + 1);
            if (r != map.end() && r->second - static_cast<long>(nums[i]) <= t) return true;

            map[id] = nums[i];
            if (map.size() > k) map.erase(getId(t, nums[i - k]));
        }
        return false;
    }

private:
    long getId(long t, long n) {

        if (n >= 0) return n / (t + 1);
        return (n + 1) / (t + 1) - 1;
    }
};