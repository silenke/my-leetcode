#include "..\..\leetcode.h"

class Solution {
public:
    int minCut(string s) {

        const int n = s.size();
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                dp[r + 1] = min(dp[r + 1], dp[l] + 1);
                l--, r++;
            }
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                dp[r + 1] = min(dp[r + 1], dp[l] + 1);
                l--, r++;
            }
        }
        return dp[n] - 1;
    }
};