#include "..\..\leetcode.h"

class Solution {
public:	
    int removeDuplicates(vector<int>& nums) {

        int r = 0;
        for (int n : nums) {
            if (r < 2 || n != nums[r - 2]) {
                nums[r++] = n;
            }
        }
        return r;
    }
};