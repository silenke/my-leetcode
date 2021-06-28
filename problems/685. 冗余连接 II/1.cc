#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {

        const int n = edges.size();
        vector<int> roots(n + 1, 0);
        vector<int> ranks(n + 1, 0);

        function<int(int)> Find = [&](int i) {
            while (roots[i] != i) {
                roots[i] = roots[roots[i]];
                i = roots[i];
            }
            return i;
        };

        function<void(int, int)> Union = [&](int i, int j) {
            if (ranks[i] > ranks[j]) swap(i, j);
            else if (ranks[i] == ranks[j]) ranks[j]++;
            roots[i] = j;
        };

        vector<int> a, b;
        for (auto& edge : edges) {
            int i = edge[0];
            int j = edge[1];
            if (roots[j]) {
                a = {roots[j], j};
                b = edge;
                edge[0] = 0;
                break;
            }
            roots[j] = i;
        };

        fill(roots.begin(), roots.end(), 0);
        for (const auto& edge : edges) {
            int i = edge[0];
            int j = edge[1];
            if (i == 0) continue;
            if (!roots[i]) roots[i] = i;
            if (!roots[j]) roots[j] = j;
            int pi = Find(i);
            int pj = Find(j);
            if (pi == pj) return a.empty() ? edge : a;
            Union(pi, pj);
        }
        return b;
    }
};