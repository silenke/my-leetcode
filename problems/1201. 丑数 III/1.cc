#include "..\..\leetcode.h"

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {

        long ab = lcm<long>(a, b);
        long bc = lcm<long>(b, c);
        long ca = lcm<long>(a, c);
        long abc = lcm(ab, c);
        int l = min({a, b, c});
        int r = INT_MAX;
        while (l < r) {
            int m = l + (r - l) / 2;
            int k = m / a + m / b + m / c - m / ab - m / bc - m / ca + m / abc;
            if (k >= n) r = m;
            else l = m + 1;
        }
        return l;
    }
};