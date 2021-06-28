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
        visited = vector<vector<bool>>(N, vector<bool>(M, false));

        int ans = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ans++;
                    dfs(grid, i, j);
                }

        return ans;
    }

private:
    int N, M;
    vector<vector<int>> d = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
    vector<vector<bool>> visited;

    void dfs(vector<vector<char>> &grid, int i, int j) {

        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int newi = i + d[k][0];
            int newj = j + d[k][1];
            if (newi >= 0 && newi < N && newj >= 0 && newj < M &&
                    grid[newi][newj] == '1' && !visited[newi][newj])
                dfs(grid, newi, newj);
        }
    }
};

int main() {

    return 0;
}