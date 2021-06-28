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
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INT_MAX));
        // dp[m][i]：m个人复印i本书最少的时间
        dp[0][0] = 0;   // 初始化2维
        for (int m = 1; m <= k; m++) {
            dp[m][0] = 0;   // 初始化1维
            for (int i = 1; i <= n; i++) {
                int sum = 0;
                for (int j = i; j >= 0; j--) {
                    dp[m][i] = min(dp[m][i], max(dp[m - 1][j], sum));
                    if (j > 0) sum += pages[j - 1];
                }
            }   
        }
        return dp[k][n];
    }
};