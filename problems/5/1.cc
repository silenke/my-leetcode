#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        if (s.empty()) return 0;

        int n = s.size();
        int start = INT_MIN;
        int len = INT_MIN;
        vector<vector<bool>> dp(n, vector<bool>(n)); // dp[i][j]：[i,j]是回文串
        for (int l = 1; l <= n; l++) {   // 遍历所有长度
            for (int i = 0; i + l - 1 < n; i++) {   // 遍历所有子串
                int j = i + l - 1;
                if (l == 1)
                    dp[i][j] = true;
                else if (l == 2)
                    dp[i][j] = s[i] == s[j];
                else
                    dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                if (dp[i][j] && l > len) {
                    len = l;
                    start = i;
                }
            }
        }
        return s.substr(start, len);
    }
};