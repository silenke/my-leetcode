#include "..\..\leetcode.h"

class Solution {
public:
    int numDecodings(string s) {

        int a, b = 1;   // dp[i - 2]，dp[i - 1]
        for (int i = 1; i <= s.size(); i++) {
            int c = 0;  // dp[i]
            int num = s[i - 1] - '0';
            if (num > 0) c = b;
            if (i >= 2) {
                num += (s[i - 2] - '0') * 10;
                if (10 <= num && num <= 26) c += a;
            }
            a = b;
            b = c;
        }
        return b;
    }
};