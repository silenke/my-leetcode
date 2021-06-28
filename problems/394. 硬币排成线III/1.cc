#include "..\..\leetcode.h"

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        const int n = values.size();
        if (n & 1 == 0) return true;
        vector<vector<int>> dp(n, vector<int>(n));
        // dp[i][j]：面对[i,j]时与对手得分的最大差
        for (int i = 0; i < n; i++) {
            dp[i][i] = values[i];
        }
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i + l - 1 < n; i++) {
                int j = i + l - 1;
                dp[i][j] = max(values[i] - dp[i + 1][j], values[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};