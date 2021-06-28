#include "..\..\leetcode.h"

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<int> d{0, 1, 0, -1, 0};

        vector<pair<int, int>> points;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                points.emplace_back(i, j);
            }
        }
        sort(points.begin(), points.end(), [&](pair<int, int>& a, pair<int, int>& b){
            return matrix[a.first][a.second] > matrix[b.first][b.second]; });

        int res = 1;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (const auto& [i, j] : points) {
            for (int k = 0; k < 4; k++) {
                int x = i + d[k];
                int y = j + d[k + 1];
                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                if (matrix[i][j] >= matrix[x][y]) continue;
                dp[i][j] = max(dp[i][j], dp[x][y]);
            }
            res = max(res, dp[i][j] += 1);
        }
        return res;
    }
};