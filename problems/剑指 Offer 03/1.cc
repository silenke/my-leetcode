#include "..\..\leetcode.h"

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {

        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i) {
                if (nums[nums[i]] != nums[i]) {
                    swap(nums[nums[i]], nums[i]);
                }
                else {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};