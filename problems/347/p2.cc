#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> map;    // map[n]：整数n出现的次数
        for (int n : nums) {
            map[n]++;
        }

        auto cmp = [&](int a, int b) { return map[a] < map[b]; };   // 最大堆
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int m = map.size() - k;    // 保存出现次数最小的m个整数
        vector<int> res;
        for (auto [n, count] : map) {
            pq.emplace(n);
            if (pq.size() > m) {
                res.emplace_back(pq.top());
                pq.pop();
            }
        }
        return res;
    }
};