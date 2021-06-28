#include "..\..\leetcode.h"

class Solution {
public:
    bool isScramble(string s1, string s2) {

        if (s1.size() != s2.size()) return false;
        const int n = s1.size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1)));
        // dp[i][j][l]：s1从位置i开始，s2从位置j开始，长度为k，是扰乱字符串
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][1] = s1[i] == s2[j];
            }
        }
        for (int l = 1; l <= n; l++) {
            for (int i = 0; i + l - 1 < n; i++) {
                for (int j = 0; j + l - 1 < n; j++) {
                    for (int k = 1; k < l; k++) {
                        if (dp[i][j][k] && dp[i + k][j + k][l - k]) {
                            dp[i][j][l] = true;
                            break;
                        }
                        if (dp[i][j + l - k][k] && dp[i + k][j][l - k]) {
                            dp[i][j][l] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};