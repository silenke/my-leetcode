#include "..\..\leetcode.h"

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        vector<int> dp(m + 1);
        // dp[j]：前i个物品装进容量为j的背包的最大价值
        for (int i = 0; i < A.size(); i++) {
            for (int j = m; j >= A[i]; j--) {
                dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
            }
        }
        return dp[m];
    }
};