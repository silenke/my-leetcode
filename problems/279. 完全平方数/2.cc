#include "..\..\leetcode.h"

class Solution {
public:
    int numSquares(int n) {

        queue<int> q;
        vector<bool> visited(n + 1);

        q.emplace(n);
        visited[n] = true;

        int depth = 0;
        while (!q.empty()) {
            depth++;
            int n = q.size();
            while (n--) {
                int i = q.front(); q.pop();
                for (int j = 1; ; j++) {
                    int k = i - j * j;
                    if (k == 0) return depth;
                    if (k < 0) break;
                    if (!visited[k]) {
                        q.emplace(k);
                        visited[k] = true;
                    }
                }
            }
        }
        return -1;
    }
};