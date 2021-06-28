#include "..\..\leetcode.h"

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        const int n = isConnected.size();
        vector<bool> visited(n, false);
        function<void(int)> dfs = [&](int i) {
            visited[i] = true;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && isConnected[i][j]) {
                    dfs(j);
                }
            }
        };
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                res++;
                dfs(i);
            }
        }
        return res;
    }
};