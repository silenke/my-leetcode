#include "..\..\leetcode.h"

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {

        const int n = points.size();
        vector<vector<int>> dis(n, vector<int>(n));
        unordered_map<int, int> counts;
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                dis[i][j] = dis[j][i] = x * x + y * y;
            }
            for (int j = 0; j < n; j++) {
                if (i != j) counts[dis[i][j]]++;
            }
            for (auto [d, count] : counts) {
                res += count * (count - 1);
            }
            counts.clear();
        }
        return res;
    }
};