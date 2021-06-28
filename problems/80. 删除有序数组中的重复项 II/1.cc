#include "..\..\leetcode.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        const int n = nums.size();
        if (n < 3) return n;
        
        int r = 2;
        for (int i = 2; i < n; i++) {
            if (nums[i] != nums[r - 2]) {
                nums[r++] = nums[i];
            }
        }
        return r;
    }
};