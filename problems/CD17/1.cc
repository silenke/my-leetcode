#include "..\..\leetcode.h"

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int robot(int n, int m, int k, int p) {
        
        const int mod = 1e9 + 7;
        
        vector<vector<int>> dp(2, vector<int>(n + 2, 0));
        // dp[i][j]：走i步来到k位置的方法数
        int curr = 0, prev;
        dp[curr][m] = 1;
        for (int i = 1; i <= k; i++) {
            prev = curr;
            curr ^= 1;
            for (int j = 1; j <= n; j++) {
                dp[curr][j] = dp[prev][j - 1] + dp[prev][j + 1];
                dp[curr][j] %= mod;
            }
        }
        return dp[curr][p];
    }
};

int main() {
    
    int n, m, k, p;
    cin >> n >> m >> k >> p;
    
    cout << Solution().robot(n, m, k, p);
    
    return 0;
}