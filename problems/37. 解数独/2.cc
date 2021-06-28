#include "..\..\leetcode.h"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {

        rows = cols = boxs = vector<bitset<9>>(9, bitset<9>());

        int count = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    count++;
                    continue;
                }
                int n = board[i][j] - '1';
                rows[i][n] = cols[j][n] = boxs[b(i, j)][n] = 1;
            }
        }
        
        dfs(board, count);
    }

private:
    vector<bitset<9>> rows, cols, boxs;

    int b(int i, int j) {

        return i / 3 * 3 + j / 3;
    }

    bitset<9> possible(int i, int j) {
        // 位置(i,j)可以填入的整数
        return ~(rows[i] | cols[j] | boxs[b(i, j)]);
    }

    pair<int, int> next(const vector<vector<char>>& board) {
        // 可填整数数量最少的位置
        pair<int, int> res;
        int minCount = INT_MAX;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') continue;
                int count = possible(i, j).count();
                if (count < minCount) {
                    minCount = count;
                    res = {i, j};
                }
            }
        }
        return res;
    }

    bool dfs(vector<vector<char>>& board, int count) {
        // count：剩余需要填入的空格数量
        if (count == 0) return true;

        auto [i, j] = next(board);
        auto bs = possible(i, j);
        int k = b(i, j);
        for (int n = 0; n < 9; n++) {
            if (!bs[n]) continue;
            board[i][j] = n + '1';
            rows[i][n] = cols[j][n] = boxs[k][n] = 1;
            if (dfs(board, count - 1)) return true;
            board[i][j] = '.';
            rows[i][n] = cols[j][n] = boxs[k][n] = 0;
        }
        return false;
    }
};