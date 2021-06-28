#include "..\..\leetcode.h"

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxGap(vector<int>& nums) {
        
        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        for (int n : nums) {
            minNum = min(minNum, n);
            maxNum = max(maxNum, n);
        }
        
        if (minNum == maxNum) return 0;
        
        int n = nums.size();
        
        vector<int> mins(n + 1, INT_MAX);
        vector<int> maxs(n + 1, INT_MIN);
        for (int x : nums) {
            int i = (long long)(x - minNum) * n / (maxNum - minNum);
            mins[i] = min(mins[i], x);
            maxs[i] = max(maxs[i], x);
        }
        
        int res = INT_MIN;
        int lastMax = INT_MAX;
        for (int i = 0; i < n + 1; i++) {
            if (mins[i] != INT_MAX) {
                res = max(res, mins[i] - lastMax);
                lastMax = maxs[i];
            }
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
    
    cout << Solution().maxGap(nums);
    
    return 0;
}