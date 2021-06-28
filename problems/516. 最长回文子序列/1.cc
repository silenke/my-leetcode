#include "..\..\leetcode.h"

class Solution {
public:
    int longestPalindromeSubseq(string s) {

        const int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        // dp[i][j]：[i,j]最长回文子序列的长度
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int i = 0; i < n - 1; i++) {
            dp[i][i + 1] = s[i] == s[i + 1] ? 2 : 1;
        }
        for (int l = 3; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};