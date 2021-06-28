#include "..\..\leetcode.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        const int m = board.size();
        const int n = board.back().size();

        vector<pair<int, int>> d{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        function<bool(int, int, int)> dfs = [&](int i, int j, int k) {
            if (k == word.size()) return true;
            if (i < 0 || i >= m || j < 0 || j >= n) return false;
            if (board[i][j] == 0 || board[i][j] != word[k]) return false;
            board[i][j] = 0;
            for (auto [x, y] : d) {
                if (dfs(i + x, j + y, k + 1)) return true;
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