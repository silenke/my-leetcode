#include "..\..\leetcode.h"

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {

        int res = 0;
        int len;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i - 1] < nums[i]) len++;
            else len = 1;
            res = max(res, len);
        }
        return res;
    }
};