#include "..\..\leetcode.h"

class Solution {
public:
    double myPow(double x, int n) {

        if (x == 0) return 0;
        long m = n;
        if (m < 0) {
            x = 1 / x;
            m = -m;
        }
        
        double res = 1;
        while (m) {
            if (m & 1) res *= x;
            x *= x;
            m >>= 1;
        }
        return res;
    }
};