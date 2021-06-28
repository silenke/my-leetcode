#include "..\..\leetcode.h"

class Solution {
public:
    bool isMatch(string s, string p) {

        const int m = s.size();
        const int n = p.size();

        vector<vector<bool>> dp(2, vector<bool>(n + 1));
        // dp[j]：s1前i个字符可以被s2前j个字符匹配
        int curr = 0, prev = 1;
        for (int i = 0; i <= m; i++) {
            curr ^= 1, prev ^= 1;
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0) {
                    dp[curr][j] = true;
                    continue;
                }
                dp[curr][j] = false;
                if (j >= 1) {
                    if (p[j - 1] != '*') {
                        if (i >= 1 && (p[j - 1] == s[i - 1] || p[j - 1] == '.')) {
                            dp[curr][j] = dp[prev][j - 1];
                        }
                    }
                    else if (j >= 2) {
                        dp[curr][j] = dp[curr][j - 2];
                        if (!dp[curr][j] && i >= 1 && (p[j - 2] == s[i - 1] || p[j - 2] == '.')) {
                            dp[curr][j] = dp[prev][j];
                        }
                    }
                }
            }
        }
        return dp[curr][n];
    }
};