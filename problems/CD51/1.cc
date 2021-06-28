#include "..\..\leetcode.h"

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    typedef long long ll;
    
    ll minCost(vector<int>& nums) {
        
        ll res = 0;
        priority_queue<ll, vector<ll>, greater<ll>> pq(nums.begin(), nums.end());
        while (pq.size() > 1) {
            ll sum = pq.top();
            pq.pop();
            sum += pq.top();
            pq.pop();
            res += sum;
            pq.emplace(sum);
        }
        return res;
    }
};

int main() {
    
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << Solution().minCost(nums);
    
    return 0;
}