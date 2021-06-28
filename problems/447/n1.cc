#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {

        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, int> map; // 到点i的距离，出现的次数
            for (int j = 0; j < points.size(); j++) {
                if (i != j) {
                    map[distance(points[i], points[j])]++;
                }
            }
            for (auto [dis, count] : map) {
                res += count * (count - 1);
            }
        }
        return res;
    }

private:
    int distance(const vector<int>& a, const vector<int>& b) {
        
        int dx = a[0] - b[0];
        int dy = a[1] - b[1];
        return dx * dx + dy * dy;
    }
};