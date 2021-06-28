#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> set(nums1.begin(), nums1.end());

        vector<int> res;
        for (int n : nums2) {
            auto it = set.find(n);
            if (it != set.end()) {
                res.emplace_back(n);
                set.erase(it);
            }
        }
        return res;
    }
};