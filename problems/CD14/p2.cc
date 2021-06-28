#include "..\..\leetcode.h"

class Solution {
public:
    int maxLength(vector<int>& nums, int k) {
        
        const int n = nums.size();
        
        vector<int> sums(n);
        vector<int> rights(n);
        sums[n - 1] = nums[n - 1];
        rights[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (sums[i + 1] <= 0) {
                sums[i] = nums[i] + sums[i + 1];
                rights[i] = rights[i + 1];
            }
            else {
                sums[i] = nums[i];
                rights[i] = i;
            }
        }
        
        int res = 0;
        int l = 0;
        int r = 0;
        int sum = 0;
        while (r < n) {
            while (r < n && sum + sums[r] <= k) {
                sum += sums[r];
                r = rights[r] + 1;
            }
            res = max(res, r - l);
            if (l < r) sum -= nums[l++];
        }
        return res;
    }
};