#include "..\..\leetcode.h"

class Solution {
public:
    int longestPalindromeSubseq(string s) {

        const int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        // dp[i][j]：[i,j]最长回文子序列的长度
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) dp[i][j] = 1;
                else {
                    if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                    else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};