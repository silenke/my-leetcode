#include "..\..\leetcode.h"

class Solution {
public:
    int numWays(int n) {

        const int mod = 1e9 + 7;
        int a = 1, b = 1;
        for (int i = 2; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c % mod;
        }
        return b;
    }
};