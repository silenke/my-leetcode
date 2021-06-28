#include "..\..\leetcode.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int Max = 1;
        int Min = 1;
        int res = INT_MIN;
        for (int n : nums) {
            if (n < 0) swap(Max, Min);
            Max = max(n, n * Max);
            Min = min(n, n * Min);
            res = max(res, Max);
        }
        return res;
    }
};