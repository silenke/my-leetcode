#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        n = board[0].size();

        visited = vector<vector<bool>>(m, vector<bool>(n, false));
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
    vector<vector<bool>> visited;

    bool dfs(const vector<vector<char>>& board, const string& word, int i, int j, int index) {

        if (index == word.size()) return true;

        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if (visited[i][j] || board[i][j] != word[index]) return false;

        visited[i][j] = true;
        for (auto [dx, dy] : d) {
            if (dfs(board, word, i + dx, j + dy, index + 1)) {
                return true;
            }
        }
        visited[i][j] = false;
        return false;
    }
};