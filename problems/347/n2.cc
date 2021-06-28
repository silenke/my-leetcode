#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> map;    // 元素：次数
        for (int n : nums) {
            map[n]++;
        }

        auto cmp = [&](int a, int b){ return map[a] < map[b]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        vector<int> res;
        for (auto [num, count] : map) {
            pq.emplace(num);
            if (pq.size() > map.size() - k) {
                res.emplace_back(pq.top());
                pq.pop();
            }
        }
        return res;
    }
};