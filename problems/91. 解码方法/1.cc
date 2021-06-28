#include "..\..\leetcode.h"

class Solution {
public:
    int numDecodings(string s) {

        const int n = s.size();
        vector<int> dp(n + 1);
        // 前i个字符的编码方法数
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            int num = s[i - 1] - '0';
            if (num > 0) dp[i] = dp[i - 1];
            if (i >= 2) {
                num += (s[i - 2] - '0') * 10;
                if (10 <= num && num <= 26) dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};