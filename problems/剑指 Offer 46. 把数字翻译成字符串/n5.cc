#include "..\..\leetcode.h"

class Solution {
public:
    int translateNum(int num) {

        int y = 0;
        int b = 1, a = 0;   // dp[i+1]，dp[i+2];
        while (num) {
            int x = num % 10;
            int c = b;
            int n = x * 10 + y;
            if (10 <= n && n <= 25) c += a;
            num /= 10;
            y = x;
            a = b;
            b = c;
        }
        return b;
    }
};