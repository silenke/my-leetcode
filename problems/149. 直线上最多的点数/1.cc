#include "..\..\leetcode.h"

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        auto my_hash = [](const pair<int, int>& k) {
            return static_cast<size_t>(k.first) << 32 ^ k.second;
        };

        int res = 0;
        unordered_map<pair<int, int>, int, decltype(my_hash)> counts(0, my_hash);
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
    pair<int, int> slope(const vector<int>& a, const vector<int>& b) {

        int x = a[0] - b[0];
        int y = a[1] - b[1];

        if (x == 0) return {0, 1};
        if (y == 0) return {1, 0};

        int d = __gcd(x, y);
        return {x / d, y / d};
    }
};