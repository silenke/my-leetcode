#include "..\..\leetcode.h"

class Solution {
public:
    void solve(vector<vector<char>>& board) {

        const int m = board.size();
        const int n = board[0].size();
        const int d[]{0, -1, 0, 1, 0};
        function<void(int, int)> bfs = [&](int i, int j) {
            // 将要查看位置(i,j)
            queue<pair<int, int>> q;
            q.emplace(i, j);
            while (!q.empty()) {
                tie(i, j) = q.front(); q.pop();
                if (i < 0 || i >= m || j < 0 || j >= n) continue;
                if (board[i][j] != 'O') continue;
                board[i][j] = 'G';
                for (int k = 0; k < 4; k++) {
                    q.emplace(i + d[k], j + d[k + 1]);
                }
            }
        };
        for (int j = 0; j < n; j++) {
            bfs(0, j), bfs(m - 1, j);
        }
        for (int i = 0; i < m; i++) {
            bfs(i, 0), bfs(i, n - 1);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'G') board[i][j] = 'O';
            }
        }
    }
};