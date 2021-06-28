#include "..\..\leetcode.h"

class Solution {
public:
    /**
     * @param A: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integer
     */
    int kSum(vector<int> &A, int k, int target) {
        // write your code here
        const int n = A.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(target + 1)));
        // dp[i][j][w]：前i个整数用j个拼出w
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int w = 0; w <= target; w++) {
                    dp[i][j][w] = dp[i - 1][j][w];
                    if (j >= 1 && w >= A[i - 1]) {
                        dp[i][j][w] += dp[i - 1][j - 1][w - A[i - 1]];
                    }
                }
            }
        }
        return dp[n][k][target];
    }
};