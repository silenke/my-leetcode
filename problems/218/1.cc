#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        vector<pair<int, int>> nums;
        nums.reserve(buildings.size() * 2);
        for (const auto& b : buildings) {
            nums.emplace_back(b[0], -b[2]);
            nums.emplace_back(b[1], b[2]);
        }

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        multiset<int> set;  // 当前所有高度
        set.insert(0);
        int last = 0;   // 上次最大高度
        for (auto [p, h] : nums) {
            if (h < 0) set.insert(-h);
            else set.erase(set.find(h));
            int curr = *set.rbegin();   // 当前最大高度
            if (curr != last) {
                res.push_back({p, curr});
                last = curr;
            }
        }
        return res;
    }
};