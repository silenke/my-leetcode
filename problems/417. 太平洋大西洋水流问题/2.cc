#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {

        const int m = matrix.size();
        if (m == 0) return {};
        const int n = matrix[0].size();
        const int d[]{0, -1, 0, 1, 0};
        vector<vector<int>> v(m, vector<int>(n));
        // 0：未访问，1：从太平洋已访问，2：从大西洋已访问
        auto bfs1 = [&](int i, int j) {
            // 将要查看位置(i,j)
            queue<pair<int, int>> q;
            q.emplace(i, j);
            v[i][j] = 1;
            while (!q.empty()) {
                tie(i, j) = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int x = i + d[k];
                    int y = j + d[k + 1];
                    if (x < 0 || x >= m || y < 0 || y >= n) continue;
                    if (v[x][y] == 1 || matrix[x][y] < matrix[i][j]) continue;
                    q.emplace(x, y);
                    v[x][y] = 1;
                }
            }
        };
        vector<vector<int>> res;
        auto bfs2 = [&](int i, int j) {
            // 将要查看位置(i,j)
            queue<pair<int, int>> q;
            if (v[i][j] == 1) res.push_back({i, j});
            q.emplace(i, j);
            v[i][j] = 2;
            while (!q.empty()) {
                tie(i, j) = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int x = i + d[k];
                    int y = j + d[k + 1];
                    if (x < 0 || x >= m || y < 0 || y >= n) continue;
                    if (v[x][y] == 2 || matrix[x][y] < matrix[i][j]) continue;
                    if (v[x][y] == 1) res.push_back({x, y});
                    q.emplace(x, y);
                    v[x][y] = 2;
                }
            }
        };
        for (int j = 0; j < n; j++) bfs1(0, j);
        for (int i = 0; i < m; i++) bfs1(i, 0);
        for (int j = 0; j < n; j++) bfs2(m - 1, j);
        for (int i = 0; i < m; i++) bfs2(i, n - 1);
        return res;
    }
};