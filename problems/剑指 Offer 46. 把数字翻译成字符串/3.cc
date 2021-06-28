#include "..\..\leetcode.h"

class Solution {
public:
    int translateNum(int num) {

        string s(to_string(num));
        const int n = s.size();
        vector<int> dp(n + 1);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];
            if (i < n - 1) {
                int m = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if (10 <= m && m < 26) dp[i] += dp[i + 2];
            }
        }
        return dp[0];
    }
};