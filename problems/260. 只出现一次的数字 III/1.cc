#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        unsigned int x = 0;
        for (int n : nums) x ^= n;
        x &= -x;
        int a = 0, b = 0;
        for (int n : nums) {
            if (n & x) a ^= n;
            else b ^= n;
        }
        return {a, b};
    }
};