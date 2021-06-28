#include "..\..\leetcode.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    int m, n;
    vector<pair<int, int>> d {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int k) {
        // 将要查看字符board[i][j]和word[k]

        if (k == word.size()) return true;

        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if (board[i][j] != word[k]) return false;

        board[i][j] = '#';
        for (auto [x, y] : d) {
            if (dfs(board, word, i + x, j + y, k + 1)) {
                return true;
            }
        }
        board[i][j] = word[k];

        return false;
    }
};