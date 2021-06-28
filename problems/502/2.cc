#include "..\..\leetcode.h"

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1;
        priority_queue<int> pq2;

        for (int i = 0; i < Capital.size(); i++) {
            pq1.emplace(Capital[i], Profits[i]);
        }

        while (k--) {
            while (!pq1.empty() && pq1.top().first <= W) {
                pq2.emplace(pq1.top().second);
                pq1.pop();
            }

            if (pq2.empty()) break;

            W += pq2.top();
            pq2.pop();
        }
        return W;
    }
};