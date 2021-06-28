#include "..\..\leetcode.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int res = INT_MIN;
        
        heights.emplace_back(-1);
        int n = heights.size();
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int j = s.top(); s.pop();
                int l = s.empty() ? -1 : s.top();
                res = max(res, heights[j] * (i - l - 1));
            }
            s.emplace(i);
        }
        return res;
    }
};