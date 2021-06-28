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
        vector<bool> dp(m + 1);
        // dp[j]：前i个物品可以装满容量j的背包
        dp[0] = true;
        for (int a : A) {
            for (int j = m; j >= a; j--) {
                dp[j] = dp[j] || dp[j - a];
            }
        }
        for (int j = m; j > 0; j--) {
            if (dp[j]) return j;
        }
        return 0;
    }
};