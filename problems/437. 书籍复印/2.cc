#include "..\..\leetcode.h"

class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        
        const int n = pages.size();
        if (k > n) k = n;
        vector<vector<int>> dp(2, vector<int>(n + 1, INT_MAX));
        // // dp[i]：m个人复印i本书最少的时间
        int curr = 0, prev = 1;
        dp[curr][0] = 0;
        for (int m = 1; m <= k; m++) {
            curr ^= 1;
            prev ^= 1;
            // 不需要初始化，因为结果不会比之前更差
            for (int i = 1; i <= n; i++) {
                int sum = 0;
                for (int j = i; j >= 0; j--) {
                    dp[curr][i] = min(dp[curr][i], max(dp[prev][j], sum));
                    if (j > 0) sum += pages[j - 1];
                }
            }
        }
        return dp[curr][n];
    }
};