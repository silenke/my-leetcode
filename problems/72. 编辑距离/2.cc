#include "..\..\leetcode.h"

class Solution {
public:
    int minDistance(string word1, string word2) {

        if (word1.size() < word2.size()) word1.swap(word2);
        const int n1 = word1.size();
        const int n2 = word2.size();
        vector<vector<int>> dp(2, vector<int>(n2 + 1));
        // dp[j]：s1前i个字符转换成s2前j个字符的最小编辑距离
        int curr = 0, prev = 1;
        for (int i = 0; i <= n1; i++) {
            curr ^= 1, prev ^= 1;
            for (int j = 0; j <= n2; j++) {
                if (i == 0) {
                    dp[curr][j] = j;
                }
                else if (j == 0) {
                    dp[curr][j] = i;
                }
                else if (word1[i - 1] == word2[j - 1]) {
                    dp[curr][j] = dp[prev][j - 1];
                }
                else {
                    dp[curr][j] = min({dp[prev][j], dp[curr][j - 1], dp[prev][j - 1]}) + 1;
                }
            }
        }
        return dp[curr][n2];
    }
};