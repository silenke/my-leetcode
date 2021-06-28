#include "..\..\leetcode.h"

class Solution {
public:
    int countDigitOne(int n) {

        int res = 0;
        for (long i = 1; i <= n; i *= 10) {
            int a = n / i;
            int b = n % i;
            res += (a + 8) / 10 * i + (a % 10 == 1) * (b + 1);
        }
        return res;
    }
};