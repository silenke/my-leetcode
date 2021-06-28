#include "..\..\leetcode.h"

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {

        auto cmp = [&](int a, int b){ return Capital[a] > Capital[b]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq1(cmp);
        for (int i = 0; i < Profits.size(); i++) {
            pq1.emplace(i);
        }

        priority_queue<int> pq2;
        while (k--) {
            while (!pq1.empty() && W >= Capital[pq1.top()]) {
                pq2.emplace(Profits[pq1.top()]); pq1.pop();
            }
            if (pq2.empty()) break;
            W += pq2.top(); pq2.pop();
        }
        return W;
    }
};