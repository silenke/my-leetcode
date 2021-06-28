#include "..\..\leetcode.h"

class Solution {
public:
    int numSquares(int n) {

        queue<int> q;
        vector<bool> visited(n + 1, false);

        q.emplace(n);
        visited[n] = true;

        int depth = 0;
        while (!q.empty()) {
            depth++;
            int k = q.size();
            while (k--) {
                int m = q.front();  // 当前节点
                q.pop();
                for (int i = 1; ; i++) {    // 边
                    int j = m - i * i;  // 下个节点
                    if (j == 0) return depth;
                    if (j < 0) break;
                    if (!visited[j]) {
                        visited[j] = true;
                        q.emplace(j);
                    }
                }
            }
        }
        return 0;
    }
};