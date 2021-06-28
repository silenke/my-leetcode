#include "..\..\leetcode.h"

class Solution {
public:
    int minMoves2(vector<int>& nums) {

        int mid = nums.size() / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        int n = *(nums.begin() + mid);
        return accumulate(nums.begin(), nums.end(), 0,
            [&](int a, int b) { return a + abs(b - n); });
    }
};