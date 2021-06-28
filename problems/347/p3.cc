#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> map;    // map[n]：整数n出现的次数
        for (int n : nums) {
            map[n]++;
        }

        unordered_map<int, vector<int>> buckets;    // buckets[count]：出现count次的所有整数
        int max_count = INT_MIN;
        for (auto [n, count] : map) {
            buckets[count].emplace_back(n);
            max_count = max(max_count, count);
        }

        vector<int> res;
        for (int i = max_count; res.size() < k; i--) {
            auto it = buckets.find(i);
            if (it != buckets.end()) {
                res.insert(res.end(), it->second.begin(), it->second.end());
            }
        }
        return res;
    }
};