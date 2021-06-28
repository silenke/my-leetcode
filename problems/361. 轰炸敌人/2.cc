#include "..\..\leetcode.h"

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {

        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        vector<vector<int>> res(m, vector<int>(n));
        for (int j = 0; j < n; j++) {
            int dp = 0;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 'W') dp = 0;
                else if (grid[i][j] == 'E') dp++;
                res[i][j] += dp;
            }
            dp = 0;
            for (int i = m - 1; i >= 0; i--) {
                if (grid[i][j] == 'W') dp = 0;
                else if (grid[i][j] == 'E') dp++;
                res[i][j] += dp;
            }
        }
        for (int i = 0; i < m; i++) {
            int dp = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'W') dp = 0;
                else if (grid[i][j] == 'E') dp++;
                res[i][j] += dp;
            }
            dp = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 'W') dp = 0;
                else if (grid[i][j] == 'E') dp++;
                res[i][j] += dp;
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