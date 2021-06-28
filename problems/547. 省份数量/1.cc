#include "..\..\leetcode.h"

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        const int n = isConnected.size();
        vector<int> parents(n, 0);
        vector<int> ranks(n, 0);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }

        function<int(int)> Find = [&](int a) {
            while (parents[a] != a) {
                parents[a] = parents[parents[a]];
                a = parents[a];
            }
            return a;
        };

        function<void(int, int)> Union = [&](int a, int b) {
            if (ranks[a] > ranks[b]) swap(a, b);
            else if (ranks[a] == ranks[b]) ranks[b]++;
            parents[a] = b;
        };

        int res = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!isConnected[i][j]) continue;
                int pi = Find(i);
                int pj = Find(j);
                if (pi != pj) {
                    res--;
                    Union(pi, pj);
                }
            }
        }
        return res;
    }
};