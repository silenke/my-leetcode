#include "..\..\leetcode.h"

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        const int l = strs.size();
        vector<int> count0(l);
        vector<int> count1(l);
        for (int i = 0; i < l; i++) {
            for (char c : strs[i]) {
                if (c == '0') count0[i]++;
                else count1[i]++;
            }
        }
        vector<vector<vector<int>>> dp(l + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        // dp[i][j][k]：前i个字符串，j个0，k个1，最大子集大小
        for (int i = 1; i <= l; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= count0[i - 1] && k >= count1[i - 1]) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - count0[i - 1]][k - count1[i - 1]] + 1);
                    }
                }
            }
        }
        return dp[l][m][n];
    }
};