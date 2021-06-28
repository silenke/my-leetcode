#include "..\..\leetcode.h"

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            int c = abs(a - b);
            if (c) pq.emplace(c);
        }
        return pq.empty() ? 0 : pq.top();
    }
};