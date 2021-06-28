#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {

        const int m = matrix.size();
        if (m == 0) return {};
        const int n = matrix[0].size();
        const int d[]{0, -1, 0, 1, 0};
        vector<vector<int>> v(m, vector<int>(n));
        function<void(int, int, int)> dfs1 = [&](int i, int j, int h) {
            if (i < 0 || i >= m || j < 0 || j >= n) return;
            if (v[i][j] == 1 || matrix[i][j] < h) return;
            v[i][j] = 1;
            for (int k = 0; k < 4; k++) {
                dfs1(i + d[k], j + d[k + 1], matrix[i][j]);
            }
        };
        vector<vector<int>> res;
        function<void(int, int, int)> dfs2 = [&](int i, int j, int h) {
            if (i < 0 || i >= m || j < 0 || j >= n) return;
            if (v[i][j] == 2 || matrix[i][j] < h) return;
            if (v[i][j] == 1) res.push_back({i, j});
            v[i][j] = 2;
            for (int k  = 0; k < 4; k++) {
                dfs2(i + d[k], j + d[k + 1], matrix[i][j]);
            }
        };
        for (int j = 0; j < n; j++) dfs1(0, j, INT_MIN);
        for (int i = 0; i < m; i++) dfs1(i, 0, INT_MIN);
        for (int j = 0; j < n; j++) dfs2(m - 1, j, INT_MIN);
        for (int i = 0; i < m; i++) dfs2(i, n - 1, INT_MIN);
        return res;
    }
};