#include "..\..\leetcode.h"

class Solution {
public:
    int translateNum(int num) {

        int a = 1, b = 1, c = 0;
        int x, y = 0;
        while (num) {
            a = b;
            x = num % 10;
            int n = x * 10 + y;
            if (10 <= n && n < 26) a += c;
            c = b;
            b = a;
            y = x;
            num /= 10;
        }
        return a;
    }
};