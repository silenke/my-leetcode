#include "..\..\leetcode.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int res = INT_MIN;
        int prev = 0;
        for (int n : nums) {
            if (prev > 0) n += prev;
            res = max(res, n);
            prev = n;
        }
        return res;
    }
};