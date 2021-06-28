#include "..\..\leetcode.h"

class Solution {
public:
    bool isMatch(string s, string p) {

        const int m = s.size();
        const int n = p.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        // dp[i][j]：s1前i个字符可以被s2前j个字符匹配
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                }
                else if (j >= 1) {
                    if (p[j - 1] != '*') {
                        if (i >= 1 && (p[j - 1] == s[i - 1] || p[j - 1] == '.')) {
                            dp[i][j] = dp[i - 1][j - 1];
                        }
                    }
                    else if (j >= 2) {
                        dp[i][j] = dp[i][j - 2];
                        if (!dp[i][j] && i >= 1 && (p[j - 2] == s[i - 1] || p[j - 2] == '.')) {
                            dp[i][j] = dp[i - 1][j];
                        }
                    }
                }
            }
        }
        return dp[m][n];
    }
};