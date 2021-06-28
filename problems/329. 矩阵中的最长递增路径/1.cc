#include "..\..\leetcode.h"

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        const int m = matrix.size();
        const int n = matrix[0].size();
        const vector<int> d{0, 1, 0, -1, 0};
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        function<int(int, int)> dfs = [&](int i, int j) {
            if (dp[i][j]) return dp[i][j];
            for (int k = 0; k < 4; k++) {
                int x = i + d[k];
                int y = j + d[k + 1];
                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                if (matrix[i][j] >= matrix[x][y]) continue;
                dp[i][j] = max(dp[i][j], dfs(x, y));
            }
            return dp[i][j] += 1;
        };

        int res = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dfs(i, j));
            }
        }
        return res;
    }
};