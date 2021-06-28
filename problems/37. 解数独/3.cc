#include "..\..\leetcode.h"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {

        row = col = box = vector<int>(9);
        int count = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') count++;
                else fill(i, j, i / 3 * 3 + j / 3, board[i][j] - '1');
            }
        }
        dfs(count, board);
    }

private:
    vector<int> row, col, box;

    void fill(int i, int j, int k, int n) {

        row[i] |= 1 << n;
        col[j] |= 1 << n;
        box[k] |= 1 << n;
    }

    void zero(int i, int j, int k, int n) {

        row[i] &= ~(1 << n);
        col[j] &= ~(1 << n);
        box[k] &= ~(1 << n);
    }

    int possible(int i, int j) {

        return ~(row[i] | col[j] | box[i / 3 * 3 + j / 3]) & ((1 << 9) - 1);
    }

    pair<int, int> next(vector<vector<char>>& board) {

        pair<int, int> res;
        int min_count = INT_MAX;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') continue;
                int c = count(possible(i, j));
                if (c < min_count) {
                    min_count = c;
                    res = {i, j};
                }
            }
        }
        return res;
    }

    bool dfs(int count, vector<vector<char>>& board) {

        if (count == 0) return true;

        auto [i, j] = next(board);
        int p = possible(i, j);
        int k = i / 3 * 3 + j / 3;
        while (p) {
            int n = __builtin_ctz(p & -p);
            board[i][j] = n + '1';
            fill(i, j, k, n);
            if (dfs(count - 1, board)) return true;
            board[i][j] = '.';
            zero(i, j, k, n);
            p &= p - 1;
        }
        return false;
    }

    int count(int p) {

        int count = 0;
        while (p) {
            count++;
            p &= p - 1;
        }
        return count;
    }
};