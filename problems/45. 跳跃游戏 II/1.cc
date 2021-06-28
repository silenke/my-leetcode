#include "..\..\leetcode.h"

class Solution {
public:
    int jump(vector<int>& nums) {

        int res = 0;
        int end = 0;
        int right = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            right = max(right, i + nums[i]);
            if (i == end) {
                res++;
                end = right;
            }
        }
        return res;
    }
};