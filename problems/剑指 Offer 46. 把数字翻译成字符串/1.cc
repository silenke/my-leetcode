#include "..\..\leetcode.h"

class Solution {
public:
    int translateNum(int num) {
        
        string s(to_string(num));
        const int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            if (i >= 2) {
                int m = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                if (10 <= m && m < 26) dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};