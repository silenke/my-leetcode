#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        if (grid.empty())
            return 0;

        N = grid.size();
        M = grid[0].size();

        int ans = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }

        return ans;
    }

private:
    int N, M;
    vector<vector<int>> d = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    void dfs(vector<vector<char>> &grid, int i, int j) {

        grid[i][j] = '0';
        for (int k = 0; k < 4; k++) {
            int newi = i + d[k][0];
            int newj = j + d[k][1];
            if (newi >= 0 && newi < N && newj >= 0 && newj < M &&
                    grid[newi][newj] == '1')
                dfs(grid, newi, newj);
        }
    }
};

int main() {

    return 0;
}