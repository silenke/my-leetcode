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
        vector<vector<int>> dp(2, vector<int>(101));
        // dp[j]：前i个整数最后调整为j的最小代价
        int curr = 0, prev = 1;
        for (int j = 0; j <= 100; j++) {
            dp[curr][j] = abs(A[0] - j);
        }
        for (int i = 1; i < A.size(); i++) {
            curr ^= 1, prev ^= 1;
            for (int j = 0; j <= 100; j++) {
                dp[curr][j] = INT_MAX;
                for (int k = max(0, j - target); k <= min(100, j + target); k++) {
                    dp[curr][j] = min(dp[curr][j], dp[prev][k] + abs(A[i] - j));
                }
            }
        }
        return *min_element(dp[curr].begin(), dp[curr].end());
    }
};