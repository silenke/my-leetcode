#include "..\leetcode.h"

class Solution {
public:
    /**
     * @param A: an integer array
     * @param V: an integer array
     * @param m: An integer
     * @return: an array
     */
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        // write your code here
        vector<int> dp(m + 1);
        // dp[j]：前i种物品装进容量为j的背包的最大价值
        for (int i = 0; i < A.size(); i++) {
            for (int j = A[i]; j <= m; j++) {
                dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
            }
        }
        return dp[m];
    }
};