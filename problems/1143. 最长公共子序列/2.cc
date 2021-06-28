#include "..\..\leetcode.h"

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        if (text1.size() < text2.size()) text1.swap(text2);
        const int n1 = text1.size();
        const int n2 = text2.size();
        vector<vector<int>> dp(2, vector<int>(n2 + 1));
        // dp[j]：s1前i个字符，s2前j个字符，最长公共子序列长度
        int curr = 0, prev = 1; 
        for (int i = 1; i <= n1; i++) {
            curr ^= 1;
            prev ^= 1;
            for (int j = 1; j <= n2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[curr][j] = dp[prev][j - 1] + 1;
                }
                else {
                    dp[curr][j] = max(dp[prev][j], dp[curr][j - 1]);
                }
            }
        }
        return dp[curr][n2];
    }
};