#include "..\..\leetcode.h"

class Solution {
public:
    int longestValidParentheses(string s) {

        const int n = s.size();
        if (n < 2) return 0;
        vector<int> dp(n, 0);   // dp[i]：以位置i结尾的最长有效括号的长度
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                int pre = i - dp[i - 1] - 1;
                if (pre >= 0 && s[pre] == '(') {
                    dp[i] = dp[i - 1] + 2;
                    if (pre > 0) dp[i] += dp[pre - 1];
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};