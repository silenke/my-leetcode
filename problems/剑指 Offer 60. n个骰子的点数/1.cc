#include "..\..\leetcode.h"

class Solution {
public:
    vector<double> dicesProbability(int n) {

        vector<vector<int>> dp(n + 1, vector<int>(n * 6 + 1, 0));
        for (int j = 1; j <= 6; j++) {
            dp[1][j] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= i * 6; j++) {
                for (int k = 1; k <= 6; k++) {
                    if (j - k < i - 1) break;
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        vector<double> res;
        int num = pow(6, n);
        for (int j = n; j <= n * 6; j++) {
            res.push_back((double)dp[n][j] / num);
        }
        return res;
    }
};