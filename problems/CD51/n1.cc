#include "..\..\leetcode.h"

class Solution {
public:
    long long minCost(vector<int>& nums) {
        
        long long res = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        while (pq.size() > 1) {
            long long sum = pq.top(); pq.pop();
            sum += pq.top(); pq.pop();
            res += sum;
            pq.emplace(sum);
        }
        return res;
    }
};