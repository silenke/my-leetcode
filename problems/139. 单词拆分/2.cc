#include "..\..\leetcode.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        const int n = s.size();
        vector<bool> dp(n + 1, false);  // dp[i]：前i个字符可以被拆分
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (const auto& str : wordDict) {
                int j = i - str.size();
                if (j < 0) continue;
                int k = 0;
                while (k < str.size() && str[k] == s[j + k]) k++;
                if (k == str.size() && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};