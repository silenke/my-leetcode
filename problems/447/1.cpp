#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Time complexity: O(n^2)
// Space complexity: O(n)

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {

        int ans = 0;
        for (int i = 0; i < points.size(); i++) {

            unordered_map<int, int> map;
            for (int j = 0; j < points.size(); j++)
                if (i != j)
                    map[dis(points[i], points[j])]++;

            for (auto &x : map)
                ans += x.second * (x.second - 1);
        }

        return ans;
    }

    int dis(const vector<int> &p1, const vector<int> &p2) {

        int disx = p1[0] - p2[0];
        int disy = p1[1] - p2[1];
        return disx * disx + disy * disy;
    }
};

int main() {

    vector<vector<int>> points = {{0, 0}, {1, 0}, {2, 0}};
    int ans = Solution().numberOfBoomerangs(points);
    cout << ans << endl;

    return 0;
}