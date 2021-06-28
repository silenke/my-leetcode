#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {

        int x = 0;
        for (int n : nums) {
            x ^= n;
        }
        int lb = x & -x;
        int a = 0, b = 0;
        for (int n : nums) {
            if (n & lb) a ^= n;
            else b ^= n;
        }
        return {a, b};
    }
};