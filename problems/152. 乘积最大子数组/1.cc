#include "..\..\leetcode.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int lastMax = 1;
        int lastMin = 1;
        int res = INT_MIN;
        for (int n : nums) {
            int currMax = max(n, max(n * lastMax, n * lastMin));
            int currMin = min(n, min(n * lastMax, n * lastMin));
            res = max(res, currMax);
            lastMax = currMax;
            lastMin = currMin;
        }
        return res;
    }
};