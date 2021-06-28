#include "..\..\leetcode.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<int> row(9), col(9), box(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int n = board[i][j] - '1';
                int k = i / 3 * 3 + j / 3;
                if ((row[i] | col[j] | box[k]) & (1 << n)) return false;
                row[i] |= 1 << n;
                col[j] |= 1 << n;
                box[k] |= 1 << n;
            }
        }
        return true;
    }
};