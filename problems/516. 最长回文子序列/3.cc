#include "..\..\leetcode.h"

class Solution {
public:
    int longestPalindromeSubseq(string s) {

        const int n = s.size();
        vector<vector<int>> dp(2, vector<int>(n));
        // dp[j]：[i,j]最长回文子序列的长度
        int curr = 0, prev = 1;
        for (int i = n - 1; i >= 0; i--) {
            curr ^= 1;
            prev ^= 1;
            for (int j = i; j < n; j++) {
                if (i == j) {
                    dp[curr][j] = 1;
                }
                else {
                    if (s[i] == s[j]) dp[curr][j] = dp[prev][j - 1] + 2;
                    else dp[curr][j] = max(dp[prev][j], dp[curr][j - 1]);
                }
            }
        }
        return dp[curr][n - 1];
    }
};