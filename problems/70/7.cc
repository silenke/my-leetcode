#include "..\..\leetcode.h"

class Solution {
public:
    int climbStairs(int n) {

        double s = sqrt(5);
        double f = pow((1 + s) / 2, n + 1) - pow((1 - s) / 2, n + 1);
        return f / s;
    }
};