#include "..\..\leetcode.h"

class Solution {
public:
    int minMoves(vector<int>& nums) {

        int m = *min_element(nums.begin(), nums.end());
        return accumulate(nums.begin(), nums.end(), 0,
            [&](int a, int b){ return a + b - m; });
    }
};