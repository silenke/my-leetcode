#include "..\..\leetcode.h"

class Solution {
public:
    bool isStraight(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int minIndex = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == 0) minIndex++;
            else if (nums[i] == nums[i + 1]) return false;
        }
        return nums.back() - nums[minIndex] < 5;
    }
};