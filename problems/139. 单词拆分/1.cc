#include "..\..\leetcode.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        string_view t(s);
        const int n = t.size();
        unordered_set<string_view> set(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 1);  // dp[i]：前i个字符可以被拆分
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            if (!dp[i]) continue;
            for (int j = i + 1; j <= n; j++) {
                if (!dp[j]) dp[j] = set.count(t.substr(i, j - i));
            }
        }
        return dp[n];
    }
};