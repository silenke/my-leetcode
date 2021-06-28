#include "..\..\leetcode.h"

class Solution {
public:
    int cuttingRope(int n) {

        if (n < 4) return n - 1;

        int a = n / 3;
        int b = n % 3;
        if (b == 0) return pow(3, a) % mod;
        if (b == 1) return pow(3, a - 1) * 4 % mod;
        return pow(3, a) * 2 % mod;
    }

private:
    const int mod = 1e9 + 7;

    long pow(long a, int n) {

        long res = 1;
        while (n) {
            if (n & 1) res = res * a % mod;
            a = a * a % mod;
            n >>= 1;
        }
        return res;
    }
};