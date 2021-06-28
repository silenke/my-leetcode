#include "..\..\leetcode.h"

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        const int n1 = s1.size();
        const int n2 = s2.size();
        if (n1 + n2 != s3.size()) return false;
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1));
        // dp[i][j]：s1前i个字符，s2前j个字符，可以交错成s3前i+j个字符
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                }
                else {
                    dp[i][j] = i > 0 && s1[i - 1] == s3[i + j - 1] && dp[i - 1][j] ||
                        j > 0 && s2[j - 1] == s3[i + j - 1] && dp[i][j - 1];
                }
            }
        }
        return dp[n1][n2];
    }
};