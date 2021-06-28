#include "..\..\leetcode.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        const int n = nums.size();
        if (n < 2) return n;

        int r = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[r]) {
                nums[++r] = nums[i];
            }
        }
        return r + 1;
    }
};