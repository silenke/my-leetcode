#include "..\..\leetcode.h"

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        // dp[j][k]：前i个字符串，j个0，k个1，最大子集大小
        for (const string& s : strs) {
            int count0 = 0, count1 = 0;
            for (char c : s) {
                if (c == '0') count0++;
                else count1++;
            }
            for (int i = m; i >= count0; i--) {
                for (int j = n; j >= count1; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - count0][j - count1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};