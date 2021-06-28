#include "..\..\leetcode.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int one = 0, two = 0, three = 0;
        for (int n : nums) {
            two |= one & n;
            one ^= n;
            three = one & two;
            one &= ~three;
            two &= ~three;
        }
        return one;
    }
};