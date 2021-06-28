#include "..\..\leetcode.h"

class Solution {
public:
    int minCut(string s) {

        const int n = s.size();
        vector<vector<bool>> valid(n, vector<bool>(n));
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                valid[l--][r++] = true;
            }
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                valid[l--][r++] = true;
            }
        }
        
        vector<int> dp(n + 1, n + 1);
        // dp[i]：前i个字符最少可以划分出的回文串个数
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (valid[j][i - 1]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n] - 1;
    }
};