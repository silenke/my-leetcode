#include "..\..\leetcode.h"

class Solution {
public:
    vector<double> dicesProbability(int n) {

        vector<int> dp(n * 6 + 1);  // dp[j]：i个骰子掷出j的次数
        for (int j = 1; j <= 6; j++) {
            dp[j] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = i * 6; j >= i; j--) {
                dp[j] = 0;
                for (int k = max(1, j - (i - 1) * 6); k <= min(6, j - (i - 1)); k++) {
                    dp[j] += dp[j - k];
                }
            }
        }
        vector<double> res;
        int num = pow(6, n);
        for (int j = n; j <= n * 6; j++) {
            res.emplace_back(static_cast<double>(dp[j]) / num);
        }
        return res;
    }
};