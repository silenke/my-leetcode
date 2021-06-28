#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        const int n = edges.size();
        vector<int> parents(n + 1, 0);
        vector<int> ranks(n + 1, 0);

        function<int(int)> Find = [&](int i) {
            while (parents[i] != i) {
                parents[i] = parents[parents[i]];
                i = parents[i];
            }
            return i;
        };

        function<void(int, int)> Union = [&](int i, int j) {
            if (ranks[i] > ranks[j]) swap(i, j);
            else if (ranks[i] == ranks[j]) ranks[j]++;
            parents[i] = j;
        };

        for (const auto& edge : edges) {
            int i = edge[0];
            int j = edge[1];
            if (!parents[i]) parents[i] = i;
            if (!parents[j]) parents[j] = j;

            int pi = Find(i);
            int pj = Find(j);
            if (pi == pj) return edge;
            Union(pi, pj);
        }
        return {};
    }
};