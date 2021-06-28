#include "..\..\leetcode.h"

class Solution {
public:
    int translateNum(int num) {

        string s(to_string(num));
        int a, b = 1, c;   // dp[i-2]，dp[i-1]，dp[i]
        for (int i = 1; i <= s.size(); i++) {
            c = b;
            if (i >= 2) {
                int n = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                if (10 <= n && n < 26) c += a;
            }
            a = b;
            b = c;
        }
        return c;
    }
};