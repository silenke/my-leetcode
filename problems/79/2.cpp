#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(n*4^l)
// Space complexity: O(l)

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        N = board.size();
        M = board[0].size();  

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (findWord(board, word, 0, i, j))
                    return true;

        return false;
    }

private:
    int N, M;
    vector<vector<int>> d = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool findWord(vector<vector<char>> &board, string word,
                  int index, int i, int j) {

        if (index == word.size() - 1)
            return board[i][j] == word[index];

        if (board[i][j] == word[index]) {
            board[i][j] = 0x0;
            for (int k = 0; k < 4; k++) {
                int ni = i + d[k][0];
                int nj = j + d[k][1];
                if (ni >= 0 && ni < N && nj >= 0 && nj < M && board[ni][nj] &&
                        findWord(board, word, index + 1, ni, nj))
                    return true;
            }
            board[i][j] = word[index];
        }

        return false;
    }
};

int main() {

    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    cout << Solution().exist(board, "ABCCED") << endl;

    return 0;
}