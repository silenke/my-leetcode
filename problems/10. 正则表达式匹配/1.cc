#include "..\..\leetcode.h"

class Solution {
public:
    bool isMatch(string s, string p) {

        const int m = s.size();
        const int n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // dp[i][j]：s前i个字符可以被p前j个字符匹配
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                }
                else if (j == 0) {
                    dp[i][j] = false;
                }
                else {
                    if (p[j - 1] != '*') {
                        if (i > 0 && (p[j - 1] == '.' || p[j - 1] == s[i - 1])) {
                            dp[i][j] |= dp[i - 1][j - 1];
                        }
                    }
                    else {
                        if (j >= 2) {
                            dp[i][j] |= dp[i][j - 2];   
                        }
                        if (i > 0 && j >= 2 && (p[j - 2] == '.' || p[j - 2] == s[i - 1])) {
                            dp[i][j] |= dp[i - 1][j];
                        }
                    }
                }
            }
        }
        return dp[m][n];
    }
};