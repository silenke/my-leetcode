#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

private:
    int m, n;
    vector<vector<bool>> visited;
    vector<pair<int, int>> d {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void dfs(const vector<vector<char>>& grid, int i, int j) {

        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (grid[i][j] == '0' || visited[i][j]) return;

        visited[i][j] = true;
        for (auto [dx, dy] : d) {
            dfs(grid, i + dx, j + dy);
        }
    }

    void bfs(const vector<vector<char>>& grid, int i, int j) {

        queue<pair<int, int>> q;
        q.emplace(i, j);
        while (!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if (grid[x][y] == '0' || visited[x][y]) continue;
            
            visited[x][y] = '0';
            for (auto [dx, dy] : d) {
                q.emplace(x + dx, y + dy);
            }
        }
    }
};