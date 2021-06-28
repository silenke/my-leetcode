#include "..\..\leetcode.h"

class Solution {
public:
    int integerBreak(int n) {

        if (n < 4) return n - 1;

        int a = n / 3;
        int b = n % 3;
        if (b == 0) return pow(3, a);
        if (b == 1) return pow(3, a - 1) * 4;
        return pow(3, a) * 2;
    }
};