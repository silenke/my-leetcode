#include "..\..\leetcode.h"

class Solution {
public:
    int movingCount(int m, int n, int k) {

        int res = 0;
        vector<vector<bool>> dp(m, vector<bool>(n));
        // dp[i][j]：可以到达位置(i,j)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) dp[i][j] = true;
                else if (sum(i) + sum(j) > k) dp[i][j] = false;
                else if (i == 0) dp[i][j] = dp[i][j - 1];
                else if (j == 0) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                res += dp[i][j];
            }
        }
        return res;
    }

private:
    int sum(int n) {

        int res = 0;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
};