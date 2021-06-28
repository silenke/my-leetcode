#include "..\..\leetcode.h"

class Solution {
public:
    int translateNum(int num) {

        string s(to_string(num));
        const int n = s.size();
        int a, b = 1, c;    // dp[i]，dp[i + 1]，dp[i + 2]
        for (int i = n - 1; i >= 0; i--) {
            a = b;
            if (i < n - 1) {
                int m = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if (10 <= m && m < 26) a += c;
            }
            c = b;
            b = a;
        }
        return a;
    }
};