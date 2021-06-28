#include "..\..\leetcode.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        int res = 0;
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                int j = s.top(); s.pop();
                int l = s.empty() ? -1 : s.top();
                res = max(res, (i - l - 1) * heights[j]);
            }
            s.emplace(i);
        }

        while (!s.empty()) {
            int j = s.top(); s.pop();
            int l = s.empty() ? -1 : s.top();
            res = max(res, (n - l - 1) * heights[j]);
        }
        return res;
    }
};