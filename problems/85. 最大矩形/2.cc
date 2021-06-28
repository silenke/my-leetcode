#include "..\..\leetcode.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        const int m = matrix.size();
        if (m == 0) return 0;
        const int n = matrix[0].size();
        if (n == 0) return 0;
        
        int res = 0;
        vector<int> heights(n + 1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') heights[j] = 0;
                else heights[j]++;
            }
            stack<int> s;
            for (int j = 0; j <= n; j++) {
                while (!s.empty() && heights[s.top()] >= heights[j]) {
                    int h = heights[s.top()]; s.pop();
                    int l = s.empty() ? -1 : s.top();
                    res = max(res, h * (j - l - 1));
                }
                s.emplace(j);
            }
        }
        return res;
    }
};