#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> map;    // 元素，次数
        for (int n : nums) {
            map[n]++;
        }

        auto cmp = [&](int a, int b) { return map[a] > map[b]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (auto [num, count] : map) {
            if (pq.size() < k) {
                pq.emplace(num);
            }
            else if (count > map[pq.top()]) {
                pq.pop();
                pq.emplace(num);
            }
        }
        
        vector<int> res;
        while (!pq.empty()) {
            res.emplace_back(pq.top());
            pq.pop();
        }
        return res;
    }
};