#include "..\..\leetcode.h"

class Solution {
public:
    int numDistinct(string s, string t) {

        const int m = s.size();
        const int n = t.size();
        vector<long> dp(n + 1);
        // dp[j]：s前i个字符中t前j个字符出现的次数
        for (int i = 0; i <= m; i++) {
            for (int j = n; j >= 0; j--) {
                if (j == 0) {
                    dp[j] = 1;
                }
                else if (i == 0) {
                    dp[j] = 0;
                }
                else if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[n];
    }
};