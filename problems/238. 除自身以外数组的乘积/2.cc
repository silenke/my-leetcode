#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        const int n = nums.size();
        vector<int> res(n, 1);
        int left = 1;
        int right = 1;
        for (int i = 0; i < n; i++) {
            res[i] *= left;
            res[n - 1 - i] *= right;
            left *= nums[i];
            right *= nums[n - 1 - i];
        }
        return res;
    }
};