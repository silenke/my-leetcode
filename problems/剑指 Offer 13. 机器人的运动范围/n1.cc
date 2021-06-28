#include "..\..\leetcode.h"

class Solution {
public:
    int movingCount(int m, int n, int k) {

        int res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        function<void(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n) return;
            if (visited[i][j]) return;
            if (sum(i) + sum(j) > k) return;
            res++;
            visited[i][j] = true;
            for (int l = 0; l < 4; l++) {
                dfs(i, j + 1);
                dfs(i + 1, j);
            }
        };
        dfs(0, 0);
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