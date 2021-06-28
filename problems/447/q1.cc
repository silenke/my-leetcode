#include "..\..\leetcode.h"

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {

        int n = points.size();
        vector<vector<int>> dis(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                dis[i][j] = dis[j][i] = distance(points[i], points[j]);
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> map;
            for (int j = 0; j < points.size(); j++) {
                if (i != j) {
                    map[dis[i][j]]++;
                }
            }
            for (auto [d, count] : map) {
                res += count * (count - 1);
            }
        }
        return res;
    }

private:
    int distance(vector<int>& a, vector<int>& b) {
        
        int x = a[0] - b[0];
        int y = a[1] - b[1];
        return x * x + y * y;
    }
};