#include "..\..\leetcode.h"

class Solution {
public:
    int movingCount(int m, int n, int k) {

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(m, n, k, 0, 0, visited); 
    }

private:
    vector<pair<int, int>> d{{0, 1}, {1, 0}};

    int dfs(int m, int n, int k, int i, int j, vector<vector<bool>>& visited) {

        if (i < 0 || i >= m || j < 0 || j >= n) return 0;

        if (visited[i][j]) return 0;
        visited[i][j] = true;
        if (sum(i) + sum(j) > k) return 0;

        int res = 0;
        for (auto [x, y] : d) {
            res += dfs(m, n, k, i + x, j + y, visited);
        }
        return res + 1;
    }

    int sum(int n) {

        int res = 0;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
};