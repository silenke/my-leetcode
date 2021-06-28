#include "..\..\leetcode.h"

class Solution {
public:
    /*
     * @param A: An integer array
     * @param target: An integer
     * @return: An integer
     */
    int MinAdjustmentCost(vector<int> &A, int target) {
        // write your code here
        const int n = A.size();
        vector<vector<int>> dp(n + 1, vector<int>(101));
        // dp[i][j]：前i个整数最后调整为j的最小代价
        for (int j = 0; j <= 100; j++) {
            dp[1][j] = abs(A[0] - j);
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= 100; j++) {
                dp[i][j] = INT_MAX;
                for (int k = max(0, j - target); k <= min(100, j + target); k++) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(A[i - 1] - j));
                }
            }
        }
        return *min_element(dp[n].begin(), dp[n].end());
    }
};