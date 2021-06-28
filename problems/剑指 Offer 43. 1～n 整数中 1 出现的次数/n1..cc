#include "..\..\leetcode.h"

class Solution {
public:
    int countDigitOne(int n) {

        int res = 0;
        for (long i = 1; i <= n; i *= 10) {
            int a = n / i / 10;
            int b = n / i % 10;
            int c = n % i;
            if (b < 1) res += a * i;
            else if (b == 1) res += a * i + c + 1;
            else res += (a + 1) * i;
        }
        return res;
    }
};