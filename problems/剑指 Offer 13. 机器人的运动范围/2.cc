#include "..\..\leetcode.h"

class Solution {
public:
    int movingCount(int m, int n, int k) {

        vector<pair<int, int>> d{{0, 1}, {1, 0}};

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        q.emplace(0, 0);
        visited[0][0] = true;
        int res = 0;
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            res++;
            for (auto [x, y] : d) {
                int a = i + x;
                int b = j + y;
                if (a < 0 || a >= m || b < 0 || b >= n) continue;
                if (visited[a][b]) continue;
                visited[a][b] = true;
                if (a % 10 + a / 10 + b % 10 + b / 10 > k) continue;
                q.emplace(a, b);
            }
        }
        return res;
    }
};