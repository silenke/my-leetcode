#include "..\..\leetcode.h"

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {

        if (grid.empty() || grid[0].empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));
        vector<vector<int>> res(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 0;
                if (grid[i][j] != 'W') {
                    dp[i][j] = grid[i][j] == 'E';
                    if (i > 0) dp[i][j] += dp[i - 1][j];
                }
                res[i][j] += dp[i][j];
            }
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 0;
                if (grid[i][j] != 'W') {
                    dp[i][j] = grid[i][j] == 'E';
                    if (i < m - 1) dp[i][j] += dp[i + 1][j];
                }
                res[i][j] += dp[i][j];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 0;
                if (grid[i][j] != 'W') {
                    dp[i][j] = grid[i][j] == 'E';
                    if (j > 0) dp[i][j] += dp[i][j - 1];
                }
                res[i][j] += dp[i][j];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = n - 1; j >= 0; j--) {
                dp[i][j] = 0;
                if (grid[i][j] != 'W') {
                    dp[i][j] = grid[i][j] == 'E';
                    if (j < n - 1) dp[i][j] += dp[i][j + 1];
                }
                res[i][j] += dp[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') {
                    ans = max(ans, res[i][j]);
                }
            }
        }
        return ans;
    }
};