#include "..\..\leetcode.h"

class Solution {
public:
    int cuttingRope(int n) {

        if (n < 4) return n - 1;

        const int mod = 1e9 + 7;
        long res = 1;
        while (n > 4) {
            res = res * 3 % mod;
            n -= 3;
        }
        return res * n % mod;
    }
};