#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> map;    // 元素，次数
        int max_count = INT_MIN;
        for (int n : nums) {
            max_count = max(max_count, ++map[n]);
        }

        unordered_map<int, vector<int>> buckets;    // 次数，元素
        for (auto [num, count] : map) {
            buckets[count].emplace_back(num);
        }

        vector<int> res;
        int count = 0;
        for (int i = max_count; i > 0; i--) {
            res.insert(res.back(), buckets[i].begin(), buckets[i].end());
            count += buckets[i].size();
            if (count == k) break;
        }
        return res;
    }
};