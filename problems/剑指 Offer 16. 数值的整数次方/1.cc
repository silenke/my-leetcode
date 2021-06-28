#include "..\..\leetcode.h"

class Solution {
public:
    double myPow(double x, int n) {

        if (x == 0) return 0;

        double res = 1;
        if (n < 0) {
            x = 1 / x;
            if (n == INT_MIN) {
                n = INT_MAX;
                res = 1 / x;
            }
            else {
                n = -n;
            }
        }
        
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }
};