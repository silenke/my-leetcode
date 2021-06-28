#include "..\..\leetcode.h"-06661 7777777777777777777777777777777777777777777777777777777  00

class Solution {
public:
    int movingCount(int m, int n, int k) {

        int res = 0;
        vector<bool> dp(n); // dp[j]：可以到达位置(i,j)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) dp[j] = true;
                else if (sum(i) + sum(j) > k) dp[j] = false;
                else if (j > 0) dp[j] = dp[j] || dp[j - 1];
                res += dp[j];
            }
        }
        return res;
    }

private:
    int sum(int n) {

        int res = 0;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
};