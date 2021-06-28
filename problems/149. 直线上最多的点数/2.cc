#include "..\..\leetcode.h"

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        int res = 0;
        unordered_map<int, int> counts;
        const int n = points.size();
        for (int i = 0; i < n; i++) {
            int same_count = 1;
            int max_count = 0;
            for (int j = i + 1; j < n; j++) {
                if (points[i] == points[j]) {
                    same_count++;
                }
                else {
                    max_count = max(max_count, ++counts[slope(points[i], points[j])]);
                }
            }
            res = max(res, same_count + max_count);
            counts.clear();
        }
        return res;
    }

private:
    int slope(const vector<int>& a, const vector<int>& b) {

        int x = a[0] - b[0];
        int y = a[1] - b[1];

        if (x == 0) return 1;
        if (y == 0) return 1 << 16;

        int d = __gcd(x, y);
        return static_cast<unsigned int>(y / d) << 16 | (x / d);
    }
};