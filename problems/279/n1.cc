#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {

        queue<int> q;
        vector<bool> visited(n + 1, false);

        q.emplace(n);
        visited[n] = true;
        
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int num = q.front();
                q.pop();
                for (int i = 1; ; i++) {    // i：边
                    int adj = num - i * i;
                    if (adj < 0) {
                        break;
                    }
                    else if (adj == 0) {
                        return level + 1;
                    }
                    else if (!visited[adj]) {
                        q.emplace(adj);
                        visited[adj] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};