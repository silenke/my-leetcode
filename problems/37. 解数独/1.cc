#include "..\..\leetcode.h"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        vector<vector<bool>> rows(9, vector<bool>(10, false));
        vector<vector<bool>> cols(9, vector<bool>(10, false));
        vector<vector<bool>> boxs(9, vector<bool>(10, false));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int n = board[i][j] - '0';
                rows[i][n] = cols[j][n] = boxs[i / 3 * 3 + j / 3][n] = true;
            }
        }

        function<bool(int, int)> dfs = [&](int i, int j) {

            if (i == 9) return true;

            int y = (j + 1) % 9;
            int x = y ? i : i + 1;

            if (board[i][j] != '.') return dfs(x, y);

            for (int n = 1; n <= 9; n++) {
                int b = i / 3 * 3 + j / 3;
                if (!rows[i][n] && !cols[j][n] && !boxs[b][n]) {
                    board[i][j] = n + '0';
                    rows[i][n] = cols[j][n] = boxs[b][n] = true;
                    if (dfs(x, y)) return true;
                    board[i][j] = '.';
                    rows[i][n] = cols[j][n] = boxs[b][n] = false;
                }
            }
            return false;
        };

        dfs(0, 0);
    }
};