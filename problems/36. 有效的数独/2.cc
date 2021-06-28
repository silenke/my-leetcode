#include "..\..\leetcode.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<bitset<9>> rows(9);
        vector<bitset<9>> cols(9);
        vector<bitset<9>> boxs(9);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int k = i / 3 * 3 + j / 3;
                int n = board[i][j] - '1';
                if (rows[i][n] || cols[j][n] || boxs[k][n]) return false;
                rows[i][n] = cols[j][n] = boxs[k][n] = true;
            }
        }
        return true;
    }
};