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
        vector<int> dp(n);
        // dp[j]：面对[i,j]时与对手的最大差
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                dp[j] = max(values[i] - dp[j], values[j] - dp[j - 1]);
            }
        }
        return dp[n - 1] >= 0;
    }
};