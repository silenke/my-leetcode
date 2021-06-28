#include "..\..\leetcode.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int res = INT_MIN;
        int sum = 0;
        for (int n : nums) {
            sum += n;
            res = max(res, sum);
            if (sum < 0) sum = 0;
        }
        return res;
    }
};