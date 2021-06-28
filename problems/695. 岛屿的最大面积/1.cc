#include "..\..\leetcode.h"

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        const int m = grid.size();
        const int n = grid[0].size();
        const vector<int> d{0, 1, 0, -1, 0};
        function<int(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n) return 0;
            if (grid[i][j] == 0) return 0;
            grid[i][j] = 0;
            int count = 1;
            for (int k = 0; k < 4; k++) {
                count += dfs(i + d[k], j + d[k + 1]);
            }
            return count;
        };
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dfs(i, j));
            }
        }
        return res;
    }
};