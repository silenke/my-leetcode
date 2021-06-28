#include "..\..\leetcode.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        int res = 0;
        vector<int> heights(n + 1, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;
            }
            stack<int> s;
            for (int j = 0; j <= n; j++) {
                while (!s.empty() && heights[s.top()] >= heights[j]) {
                    int k = s.top(); s.pop();
                    int l = s.empty() ? -1 : s.top();
                    res = max(res, (j - l - 1) * heights[k]);
                }
                s.emplace(j);
            }
        }
        return res;
    }
};