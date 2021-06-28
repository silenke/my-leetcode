#include "..\..\leetcode.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        const int m = board.size();
        const int n = board[0].size();
        int d[]{0, 1, 0, -1, 0};
        function<bool(int, int, int)> dfs = [&](int i, int j, int k) {
            if (k == word.size()) return true;
            if (i < 0 || i >= m || j < 0 || j >= n) return false;;
            if (board[i][j] != word[k]) return false;
            board[i][j] = '#';
            for (int l = 0; l < 4; l++) {
                if (dfs(i + d[l], j + d[l + 1], k + 1)) return true;
            }
            board[i][j] = word[k];
            return false;
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0)) return true;
            }
        }
        return false;
    }
};