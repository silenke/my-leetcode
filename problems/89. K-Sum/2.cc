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
        vector<vector<int>> dp(k + 1, vector<int>(target + 1));
        // dp[j][w]：前i个整数使用j个拼出w
        dp[0][0] = 1;
        for (int i = 0; i < A.size(); i++) {
            for (int j = k; j >= 1; j--) {
                for (int w = target; w >= A[i]; w--) {
                    dp[j][w] += dp[j - 1][w - A[i]];
                }
            }
        }
        return dp[k][target];
    }
};