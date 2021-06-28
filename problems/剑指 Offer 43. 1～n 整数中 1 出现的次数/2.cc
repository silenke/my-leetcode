#include "..\..\leetcode.h"

class Solution {
public:
    int countDigitOne(int n) {

        int res = 0;
        for (int i = 1; ; i *= 10) {
            int a = n / i;
            int b = n % i;
            int c = a % 10;
            a /= 10;
            if (c > 1) res += (a + 1) * i;
            else if (c == 1) res += a * i + b + 1;
            else res += a * i;
            if (i > n / 10) break;
        }
        return res;
    }
};