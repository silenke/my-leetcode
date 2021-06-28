#include "..\..\leetcode.h"

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        const int n = A.size();
        int res = 0;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        // dp[i][j]：前i个物品可以装满容量j的背包
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= A[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - A[i - 1]];
                }
                if (dp[i][j]) res = j;
            }
        }
        return res;
    }
};