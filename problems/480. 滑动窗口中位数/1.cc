#include "..\..\leetcode.h"

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        if (k == 0) return {};

        vector<double> res;
        multiset<int> set(nums.begin(), nums.begin() + k);
        auto it = next(set.begin(), (k - 1) / 2);
        for (int i = k; i <= nums.size(); i++) {
            res.push_back((static_cast<double>(*it) + *next(it, (k + 1) & 1)) * 0.5);
            if (i == nums.size()) break;
            set.insert(nums[i]);
            if (nums[i] < *it) --it;
            if (nums[i - k] <= *it) ++it;
            set.erase(set.lower_bound(nums[i - k]));
        }
        return res;
    }
};