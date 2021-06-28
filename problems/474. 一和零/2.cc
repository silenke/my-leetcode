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
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // dp[j][k]：前i个字符串，j个0，k个1，最大子集大小
        for (int i = 0; i < l; i++) {
            for (int j = m; j >= count0[i]; j--) {
                for (int k = n; k >= count1[i]; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - count0[i]][k - count1[i]] + 1);
                }
            }
        }
        return dp[m][n];
    }
};