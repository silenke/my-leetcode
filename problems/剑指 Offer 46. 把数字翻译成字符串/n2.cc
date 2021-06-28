#include "..\..\leetcode.h"

class Solution {
public:
    int translateNum(int num) {

        string s(to_string(num));
        int a = 0, b = 1;   // dp[i-2]，dp[i-1];
        for (int i = 1; i <= s.size(); i++) {
            int c = b;  // dp[i];
            if (i > 1) {
                int m = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
                if (10 <= m && m <= 25) c += a;
            }
            a = b;
            b = c;
        }
        return b;
    }
};