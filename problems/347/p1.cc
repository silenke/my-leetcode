#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> map;    // map[n]：整数n出现的次数
        for (int n : nums) {
            map[n]++;
        }
        
        auto cmp = [&](int a, int b) { return map[a] > map[b]; };   // 最小堆
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (auto [n, count] : map) {    // 保存出现次数最小的k个整数
            if (pq.size() < k) {
                pq.emplace(n);
            }
            else if (count > map[pq.top()]) {
                pq.pop();
                pq.emplace(n);
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