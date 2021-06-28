#include "..\..\leetcode.h"

class Solution {
public:
    vector<double> dicesProbability(int n) {

        vector<vector<int>> dp(2, vector<int>(n * 6 + 1, 0));
        bool curr = 0, prev = 1;
        for (int j = 1; j <= 6; j++) {
            dp[curr][j] = 1;
        }
        for (int i = 2; i <= n; i++) {
            curr ^= 1;
            prev ^= 1;
            for (int j = i; j <= i * 6; j++) {
                dp[curr][j] = 0;
                if (i <= j && j <= i * 6) {
                    for (int k = 1; k <= 6; k++) {
                        if (j - k < i - 1) break;
                        dp[curr][j] += dp[prev][j - k];
                    }    
                }
            }
        }
        vector<double> res;
        int num = pow(6, n);
        for (int j = n; j <= n * 6; j++) {
            res.push_back((double)dp[curr][j] / num); 
        }
        return res;
    }
};