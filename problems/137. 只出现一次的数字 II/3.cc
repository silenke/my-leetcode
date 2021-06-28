#include "..\..\leetcode.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int one = 0, two = 0;
        for (int n : nums) {
            one = one ^ n & ~two;
            two = two ^ n & ~one;
        }
        return one;
    }
};