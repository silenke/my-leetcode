#include "..\..\leetcode.h"

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& costs, vector<int>& profits, long long w, int k) {
        
        vector<int> nums(costs.size());
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = i;
        }
        
        auto cmp1 = [&](int a, int b){ return costs[a] > costs[b]; };
        priority_queue<int, vector<int>, decltype(cmp1)> pq1(nums.begin(), nums.end(), cmp1);
        
        auto cmp2 = [&](int a, int b){ return profits[a] < profits[b]; };
        priority_queue<int, vector<int>, decltype(cmp2)> pq2(cmp2);
        
        while (k--) {
            while (!pq1.empty() && costs[pq1.top()] <= w) {
                pq2.emplace(pq1.top());
                pq1.pop();
            }
            
            if (pq2.empty()) break;
            
            w += profits[pq2.top()];
            pq2.pop();
        }
        return w;
    }
};

int main() {
    
    int n, w, k;
    cin >> n >> w >> k;
    
    vector<int> costs(n), profits(n);
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> profits[i];
    }
    
    cout << Solution().maxProfit(costs, profits, w, k);
    
    return 0;
}