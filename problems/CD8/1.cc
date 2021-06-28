#include "..\..\leetcode.h"

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums, int k) {
        
        int res = 0;
        int l = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum > k) {
                sum -= nums[l++];
            }
            if (sum == k) {
                res = max(res, i - l + 1);
            }
        }
        return res;
    }
};

int main() {
    
    int n, k;
    cin >> n >> k;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << Solution().maxLength(nums, k);
    
    return 0;
}