#include "..\..\leetcode.h"

class Solution {
public:
    bool isStraight(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int count = 0;
        int gap = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == 0) count++;
            else {
                int sub = nums[i + 1] - nums[i];
                if (sub == 0) return false;
                gap += sub - 1;
            }
        }
        return count >= gap;
    }
};