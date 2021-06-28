#include "..\..\leetcode.h"

class Solution {
public:
    int fib(int n) {

        if (n == 0) return 0;
        const int mod = 1e9 + 7;
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; i++) {
            c = (a + b) % mod;
            a = b;
            b = c;
        }
        return b;
    }
};