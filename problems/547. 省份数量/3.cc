#include "..\..\leetcode.h"

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        const int n = isConnected.size();
        vector<bool> visited(n, false);
        queue<int> q;
        function<void(int)> bfs = [&](int i) {
            q.emplace(i);
            while (!q.empty()) {
                int j = q.front(); q.pop();
                visited[j] = true;
                for (int k = 0; k < n; k++) {
                    if (!visited[k] && isConnected[j][k]) {
                        q.emplace(k);
                    }
                }
            }
        };
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                res++;
                bfs(i);
            }
        }
        return res;
    }
};