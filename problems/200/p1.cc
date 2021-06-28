#include "..\..\leetcode.h"

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();
        
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    bfs(grid, i, j);
                }
            }
        }
        return res;
    }

private:
    int m, n;
    vector<pair<int, int>> d {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void dfs(vector<vector<char>>& grid, int i, int j) {
        
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (grid[i][j] == '0') return;

        grid[i][j] = '0';
        for (auto [x, y] : d) {
            dfs(grid, i + x, j + y);
        }
    }

    void bfs(vector<vector<char>>& grid, int i, int j) {

        queue<pair<int, int>> q;
        q.emplace(i, j);
        while (!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if (grid[x][y] == '0') continue;
            
            grid[x][y] = '0';
            for (auto [dx, dy] : d) {
                q.emplace(x + dx, y + dy);
            }
        }
    }
};