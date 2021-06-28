#include "..\..\leetcode.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        const int n = triangle.size();
        for (int i = 1; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (j == i) triangle[i][j] += triangle[i - 1][j - 1];
                else if (j == 0) triangle[i][j] += triangle[i - 1][j];
                else triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
        return *min_element(triangle[n - 1].begin(), triangle[n - 1].end());
    }
};