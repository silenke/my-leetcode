#include "..\..\leetcode.h"

class Solution {
public:
    int nthUglyNumber(int n) {

        static vector<int> nums{1};
        static int i2 = 0;
        static int i3 = 0;
        static int i5 = 0;
        while (nums.size() < n) {
            int next2 = nums[i2] * 2;
            int next3 = nums[i3] * 3;
            int next5 = nums[i5] * 5;
            int next = min({next2, next3, next5});
            if (next2 == next) i2++;
            if (next3 == next) i3++;
            if (next5 == next) i5++;
            nums.emplace_back(next);
        }
        return nums[n - 1];
    }
};