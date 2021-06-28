#include "..\..\leetcode.h"

class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> dp(n);
        // dp[i][j]：到达位置(i,j)的路径数
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) dp[j] = 1;
                else dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};