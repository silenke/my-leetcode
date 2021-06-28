#include "..\..\leetcode.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {

        auto find = [&](int l, int r, int target) {
            while (l < r) {
                int m = l + (r - l) / 2;
                if (nums[m] >target) r = m;
                else l = m + 1;
            }
            return l;
        };
        int l = find(0, nums.size(), target - 1);
        int r = find(l, nums.size(), target);
        return r - l;
    }
};