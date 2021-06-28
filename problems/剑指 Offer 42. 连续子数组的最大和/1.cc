#include "..\..\leetcode.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int pre = INT_MIN;
        int res = INT_MIN;
        for (int n : nums) {
            pre = n + max(pre, 0);
            res = max(res, pre);
        }
        return res;
    }
};