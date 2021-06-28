#include "..\..\leetcode.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<vector<bool>> rows(9, vector<bool>(10));
        vector<vector<bool>> cols(9, vector<bool>(10));
        vector<vector<bool>> boxs(9, vector<bool>(10));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int b = i / 3 * 3 + j / 3;
                if (board[i][j] == '.') continue;
                int n = board[i][j] - '1';
                if (rows[i][n] || cols[j][n] || boxs[b][n]) return false;
                rows[i][n] = cols[j][n] = boxs[b][n] = true;
            }
        }
        return true;
    }
};