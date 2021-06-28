#include "..\..\leetcode.h"

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {

        if (costs.empty()) return 0;

        int n = costs.size();
        int k = costs[0].size();

        vector<vector<int>> dp(2, vector<int>(k));
        int curr = 0, prev = 1;
        for (int i = 1; i <= n; i++) {
            curr ^= 1;
            prev ^= 1;
            int j1 = 0, j2 = 0;
            int min1 = INT_MAX, min2 = INT_MAX;
            for (int j = 0; j < k; j++) {
                if (dp[prev][j] < min1) {
                    min2 = min1;
                    j2 = j1;
                    min1 = dp[prev][j];
                    j1 = j;
                }
                else if (dp[prev][j] < min2) {
                    min2 = dp[prev][j];
                    j2 = j;
                }
            }
            for (int j = 0; j < k; j++) {
                if (j != j1) {
                    dp[curr][j] = dp[prev][j1] + costs[i - 1][j];
                }
                else {
                    dp[curr][j] = dp[prev][j2] + costs[i - 1][j];
                }
            }
        }
        return *min_element(dp[curr].begin(), dp[curr].end());
    }
};