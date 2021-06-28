#include "..\..\leetcode.h"

class Solution {
public:
    void solve(vector<vector<char>>& board) {

        const int m = board.size();
        const int n = board[0].size();
        const int d[]{0, -1, 0, 1, 0};
        function<void(int, int)> dfs = [&](int i, int j) {
            // 将要查看位置(i,j)
            if (i < 0 || i >= m || j < 0 || j >= n) return;
            if (board[i][j] != 'O') return;
            board[i][j] = 'G';
            for (int k = 0; k < 4; k++) {
                dfs(i + d[k], j + d[k + 1]);
            }
        };
        for (int j = 0; j < n; j++) {
            dfs(0, j), dfs(m - 1, j);
        }
        for (int i = 0; i < m; i++) {
            dfs(i, 0), dfs(i, n - 1);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'G') board[i][j] = 'O';
            }
        }
    }
};