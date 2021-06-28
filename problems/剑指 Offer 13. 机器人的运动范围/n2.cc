#include "..\..\leetcode.h"

class Solution {
public:
    int movingCount(int m, int n, int k) {

        int res = 0;
        int d[]{0, 1, 0};
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n));
        q.emplace(0, 0);
        visited[0][0] = true;
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            res++;
            for (int l = 0; l < 2; l++) {
                int x = i + d[l];
                int y = j + d[l + 1];
                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                if (visited[x][y]) continue;
                visited[x][y] = true;
                if (sum(x) + sum(y) > k) continue;
                q.emplace(x, y);
            }
        }
        return res;
    }

private:
    int sum(int n) {

        int res = 0;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
};