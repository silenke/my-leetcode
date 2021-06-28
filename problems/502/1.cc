#include "..\..\leetcode.h"

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {

        vector<int> nums(Capital.size());
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = i;
        }
        
        auto cmp1 = [&](int a, int b){ return Capital[a] > Capital[b]; };
        priority_queue<int, vector<int>, decltype(cmp1)> pq1(nums.begin(), nums.end(), cmp1);
        
        auto cmp2 = [&](int a, int b){ return Profits[a] < Profits[b]; };
        priority_queue<int, vector<int>, decltype(cmp2)> pq2(cmp2);
        
        while (k--) {
            while (!pq1.empty() && Capital[pq1.top()] <= W) {
                pq2.emplace(pq1.top());
                pq1.pop();
            }
            
            if (pq2.empty()) break;
            
            W += Profits[pq2.top()];
            pq2.pop();
        }
        return W;
    }
};